#include<iostream>
using namespace std;
int main()
{
int a[2],cnt1=0,cnt2=0,cnt3=0;
cin>>a[0]>>a[1];
for(int i=0;i<2;++i)
{
if(a[i]==1||a[i]==3||a[i]==5||a[i]==7||a[i]==8||a[i]==10||a[i]==12)
cnt1++;
else
if(a[i]==2)
cnt2++;
else
if(a[i]==4||a[i]==6||a[i]==9||a[i]==11)
cnt3++;
}

if(cnt1==2||cnt2==2||cnt3==2)
cout<<"Yes";
else
cout<<"No";

}