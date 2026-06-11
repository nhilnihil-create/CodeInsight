#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
int a[10],b[111];
int main()
{
    int s=0;
    for(int i=1;i<=3;i++)
    {
        cin>>a[i];//输入颜色
        b[a[i]]++;//标记入桶
    }
    for(int i=0;i<=111;i++)
    {
        if(b[i]>0)//判断
        {
            s++;//计数
        }
    }
    cout<<s;
}
