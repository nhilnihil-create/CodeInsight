#include<bits/stdc++.h>
#define pi acos(-1)
#define mx 1000000000
#define mod 1000000009
#define pii pair<int,int>
#define psi pair<string,int>
#define vi vector<int>
typedef long long ll;
using namespace std;
void fastio()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("inputf.txt", "r", stdin);
    freopen("outputf.txt", "w", stdout);
#endif
    fastio();
    int i,j,t,n,m;
    //cin>>t;
    //while(t--){
     cin>>n>>m;
     vector<string>v(n);
     for(i=0;i<n;i++)cin>>v[i];
     sort(v.begin(),v.end());
     for(i=0;i<n;i++)cout<<v[i]; 
    //}
 return 0;
}

