#include <stdarg.h>
#include <unistd.h>

typedef	struct s_flags
{
	int	index;
	int len;
	int	width;
	int precision;
	int negative;
	int zero_count;
	int count;
	va_list args;

}	t_flags;

static void init_flags(t_flags *flags)
{
	flags->index = 0;
	flags->count = 0;
}

static void reset_flags(t_flags *flags)
{
	flags->len = 0;
	flags->width = 0;
	flags->precision = -1;
	flags->negative = 0;
	flags->zero_count = 0;
}

static void ft_putchar(char c)
{
	write(1, &c, 1);
}

static void ft_putstr_len(const char *s, int max_int)
{
	int index;

	index = 0;
	while (s[index] && index < max_int)
		ft_putchar(s[index++]);
}

static int ft_strlen(const char *s)
{
	int len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

static int ft_nbrlen(long nbr, int base_len)
{
	int len;

	len = 1;
	while (nbr >= base_len)
	{
		nbr /= base_len;
		len++;
	}
	return (len);
}

static void ft_putnbr_base(long nbr, int base_len, char *base)
{
	if (nbr >= base_len)
	{
		ft_putnbr_base((nbr / base_len), base_len, base);
		ft_putnbr_base((nbr % base_len), base_len, base);
	}
	else
		ft_putchar(base[nbr]);
}

static void ft_print_till(const char *s, char c, t_flags *flags)
{
	while (s[flags->index] && s[flags->index] != c)
	{
		ft_putchar(s[flags->index]);
		flags->index++;
		flags->count++;
	}
}

static int ft_isdigit(char c)
{
	return (c >= '0' && c<= '9');
}

static void parse_flags(const char *s, t_flags *flags)
{
	flags->index++;
	if (ft_isdigit(s[flags->index]))
	{
		while (ft_isdigit(s[flags->index]))
		{
			flags->width = (flags->width * 10) + (s[flags->index] - 48);
			flags->index++;
		}
	}
	if (s[flags->index] == '.')
	{
		flags->index++;
		flags->precision = 0;
		while (ft_isdigit(s[flags->index]))
		{
			flags->precision = (flags->precision * 10) + (s[flags->index] - 48);
			flags->index++;
		}
	}

}

static void print_filler(int amount, char filler, t_flags *flags)
{
	int count;

	count = 0;
	while (count++ < amount)
	{
		ft_putchar(filler);
		flags->count++;
	}
}

static void print_s(t_flags *flags)
{
	char *s;

	flags->index++;
	s = va_arg(flags->args, char *);
	if (!s)
		s = "(null)";
	flags->len = ft_strlen(s);
	if (flags->precision != -1 && (flags->precision < flags->len))
		flags->len = flags->precision;
	print_filler((flags->width - flags->len), ' ', flags);
	ft_putstr_len(s, flags->len);
	flags->count += flags->len;
}

static void print_d(t_flags *flags)
{
	long	nbr;

	flags->index++;
	nbr = va_arg(flags->args, int);
	if (nbr < 0)
	{
		flags->negative = 1;
		nbr *= -1;
	}
	flags->len = ft_nbrlen(nbr, 10);
	if (nbr == 0 && (flags->precision != -1))
		flags->len = 0;
	if ((flags->precision != -1) && flags->precision > flags->len)
		flags->zero_count = (flags->precision - flags->len);
	if (flags->negative)
		flags->len++;
	print_filler((flags->width - (flags->zero_count + flags->len)), ' ', flags);
	if (flags->negative)
		ft_putchar('-');
	print_filler(flags->zero_count, '0', flags);
	if (nbr == 0 && (flags->precision != -1))
		return ;
	ft_putnbr_base(nbr, 10, "0123456789");
	flags->count += flags->len;
}

static void print_x(t_flags *flags)
{
	unsigned int nbr;

	flags->index++;
	nbr = va_arg(flags->args, unsigned int);
	flags->len = ft_nbrlen(nbr, 16);
	if (nbr == 0 && (flags->precision != -1))
		flags->len = 0;
	if ((flags->precision != -1) && flags->precision > flags->len)
		flags->zero_count = flags->precision - flags->len;
	print_filler((flags->width - (flags->zero_count + flags->len)), ' ', flags);
	print_filler(flags->zero_count, '0', flags);
	if (nbr == 0 && (flags->precision != -1))
		return ;
	ft_putnbr_base(nbr, 16, "0123456789abcdef");
	flags->count += flags->len;
}

int ft_printf(const char *str, ...)
{
	t_flags flags;

	init_flags(&flags);
	va_start(flags.args, str);
	while (str[flags.index])
	{
		reset_flags(&flags);
		ft_print_till(str, '%', &flags);
		if (str[flags.index])
		{
			parse_flags(str, &flags);
			if (str[flags.index] == 's')
				print_s(&flags);
			else if (str[flags.index] == 'x')
				print_x(&flags);
			else if (str[flags.index] == 'd')
				print_d(&flags);
		}
	}
	return (flags.count);
}
