#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define f first
#define s second
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
/*bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
} */
int main()
{
     ll t,arr[300005];
     cin>>t;
     t*=3;
     for(int i=1;i<=t;i++)
     {
         cin>>arr[i];
     }
     sort(arr+1,arr+(t+1));
     ll cnt=0,sum=0;
     for(int i=t;i>t/3;i--)
     {
         if(cnt%2==1)
            sum+=arr[i];
         cnt++;
     }
     cout<<sum<<endl;
}
