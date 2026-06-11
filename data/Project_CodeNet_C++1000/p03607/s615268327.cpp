#include<cstdio>
#include<iostream>
#include<algorithm>
#include<ctime>
using namespace std;
long long a[1000010];
int main()
{
    int n,x=1,ans=0;//x表示一个数出现的次数，赋值1 
    cin>>n;
    for(int i=0;i<n;i++)
       cin>>a[i];
    sort(a,a+n);//先排序，更方便判断奇偶 
    for(int i=1;i<n;i++)
    {
        if(a[i]==a[i-1])//出现相同的数，x+1然后mod2 
          x=(x+1)%2;
        else
        {
            ans+=x;//单独的一个数，ans+1，x重新赋值为1，进行循环 
            x=1;
        }      
    }
    if(x%2)//再次判断 ，若不为0，则ans+1 
      ans++;
    cout<<ans<<endl;
    return 0;
}