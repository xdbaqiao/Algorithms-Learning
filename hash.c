//Hash
//
#include <stdio.h>

int Hash(char *a, int b)
{
    unsigned int c;
    c = 0;
    while(*a!='\0')
        c = (c<<5)^(*a++);
    return c%b;
}

int main()
{
    char a[20];
    scanf("%s", &a);
    int hashnum;
    hashnum = Hash(a, 20);
    printf("%d\n", hashnum);
    return 0;
}
