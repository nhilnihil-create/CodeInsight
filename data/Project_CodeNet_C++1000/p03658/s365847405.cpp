#include<bits/stdc++.h>

using namespace std;

long long n,k,he;

int a[10000];

int main()
{
cin>>n>>k;//读入
for(int i=1; i<=n; i++)
{
    cin>>a[i];//读入
    he+=a[i];//累加
}
sort(a+1,a+1+n);//从小到大排序
for(int i=1; i<=n-k; i++)
{
    he-=a[i];//从1到n-k的数都要减去
}
cout<<he<<endl;//输出结果并换行
return 0;
}