# Printf


`int ft_printf( const char * format, ... );`

This function is part of the standard library and to use it we must specify the header file **<stdio.h>**.<br />

Writes the **C** string pointed by format to the standard output (stdout). If format includes format specifiers (subsequences beginning with %), the additional arguments following format are formatted and inserted in the resulting string replacing their respective specifiers.<br />

| Specifier |	Input | example	Output example |
| --------- | ----- | ---------------------- |
| %c|	"Printing a char: [%c]\n", 'X'	| Printing a char: [X]
| %s|	"Printing a string: [%s]\n", "Hello, World"	| Printing a string: [Hello, World]
| %d|or %i	"Printing a number: [%i]\n", 386	| Printing a number: [386]

# :computer: Usage

Run **make**.<br />
Add **main.c** file.<br />
**#include "ft_printf.h"**<br />
```
#include "ft_printf.h"

int main(void)
    {
        int len;
        int len2;
        unsigned int ui;
        void *addr;

        len = ft_printf("Let's try to printf a simple sentence.\n");
        len2 = printf("Let's try to printf a simple sentence.\n");
        
        ui = (unsigned int)INT_MAX + 1024;
        
        ft_printf("Length:[%d, %i]\n", len, len);
        printf("Length:[%d, %i]\n", len2, len2);
        
        ft_printf("Negative:[%d]\n", -762534);
        printf("Negative:[%d]\n", -762534);
        
        ft_printf("Character:[%c]\n", 'H');
        printf("Character:[%c]\n", 'H');
        
        ft_printf("String:[%s]\n", "I am a string !");
        printf("String:[%s]\n", "I am a string !");
        
        len = _printf("Percent:[%%]\n");
        len2 = printf("Percent:[%%]\n");
        
        ft_printf("Len:[%d]\n", len);
        printf("Len:[%d]\n", len2);
        
        ft_printf("Unknown:[%r]\n");
        printf("Unknown:[%r]\n");
        
        return (0);
    }
    
  
