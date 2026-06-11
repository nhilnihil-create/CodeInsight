#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

ll n,m,x,k,d,i,j,index,flag=0,mini,count=0,result,odd,even,sum=0,temp,five=0,seven=0;
//cin>>n;
//string str;
//cin>>str;
ll a[20];
//ll b[200005];
for(i=0;i<3;i++)
{
    cin>>a[i];
    if(a[i]==5)  five++;
    else if(a[i]==7) seven++;
}

if(five == 2 && seven==1) cout<<"YES";
else cout<<"NO";
    return 0;
}
