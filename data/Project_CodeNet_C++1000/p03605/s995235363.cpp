#include<cstdio>
#include<iostream>
int main()
{
    std::string a;
    std::cin>>a;
    a[0]=='9'||a[1]=='9'?printf("Yes"):printf("No");
}