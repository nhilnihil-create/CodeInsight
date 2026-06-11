#include<bits/stdc++.h>
#define pi acos(-1)
#define mx 1500000
#define mod 1000000007
#define pii pair<int,int>
typedef long long ll;
using namespace std;
void fastio()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

int main()
{
    fastio();
    int i,j,t,n,k,s,l,x,y;
    //cin>>t;
    //while(t--){
     cin>>n>>k>>x>>y;
     if(k>n)k=n;
     cout<<(k*x)+(n-k)*y<<endl;
     //}
 return 0;
}
