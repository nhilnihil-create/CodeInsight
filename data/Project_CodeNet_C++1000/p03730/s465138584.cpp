#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define f first
#define s second
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define mem(arr,v) memset(arr,v,sizeof(arr))
/*bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
} */
int main()
{
     ll t,a,m,b,cnt=0;
     cin>>a>>m>>b;
     for(int i=1;i<=m;i++)
     {
         if((a*i)%m==b)
         {
             cnt=10;
             break;
         }
     }
     if(cnt==10) cout<<"YES"<<endl;
     else cout<<"NO"<<endl;
}


