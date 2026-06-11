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
         ll n,a;
         map<ll,ll>mp;
         cin>>n;
         while(n--)
         {
             cin>>a;
             if(mp[a]==1)
                mp.erase(a);
             else
                mp[a]++;
         }
         cout<<mp.size()<<endl;

}
