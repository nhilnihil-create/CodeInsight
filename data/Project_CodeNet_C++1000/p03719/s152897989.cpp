//给定三个整数A，B，C。
//如果整数C大于等于A且小于等于B，输出“Yes",否则输出”No".
#include<bits/stdc++.h>
using namespace std;
int a,b,c;
int main()
{
    cin>>a>>b>>c;
    if(c>=a&&c<=b)
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
    return 0;
}