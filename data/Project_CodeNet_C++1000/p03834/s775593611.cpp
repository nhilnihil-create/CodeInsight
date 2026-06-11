#include <stdio.h>

int main()
{
    char arr[100];
    scanf("%s", arr);
    for (int i = 0; arr[i] != '\0'; i++)
    {
        if (arr[i] == ',')
        {
            printf(" ");
        }
        else
        {
            printf("%c", arr[i]);
        }
    }
    printf("");
    return 0;
}