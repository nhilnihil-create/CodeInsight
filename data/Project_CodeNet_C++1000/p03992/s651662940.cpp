#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    char s[13];
    int i=0;
    cin >> s;
    while(s[i]!='\0'){
        if(i==4) printf(" %c", s[i]);
        else printf("%c", s[i]);
        i++;
    }
    printf("\n");
    return 0;
}
