#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll d[100009];
int main()
{
ll n;
cin>>n;
ll a[n+1];
for(int i=1;i<=n;i++)cin>>a[i];
ll c=1,an=0;
while(1)
{
    
if(c==2)break;
an++;
if(d[c]){an=-1;break;}
d[c]=1;
c=a[c];


}
cout<<an<<endl;

}