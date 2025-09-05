#include <stdio.h>
#include <string.h>

void strConcat(char a[1000], char b[1000], char c[2000])
{
    scanf("%s", a);
    scanf("%s", b);
    int lenA = strlen(a);
    int lenB = strlen(b);
    for (int i = 0; i < lenA; i++)
    {
        c[i] = a[i];
    }
    for (int i = 0; i < lenB; i++)
    {
        c[lenA + i] = b[i];
    }
    c[lenA + lenB] = '\0';
    printf("%s\n", c);
}

int main()
{
    char a[1000], b[1000], c[2000];
    strConcat(a, b, c);
    return 0;
}
