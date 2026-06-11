#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char s[10005];
int main()
{
    gets(s);
    cout << s[0] << strlen(s)-2 << s[strlen(s)-1];
    return 0;
}