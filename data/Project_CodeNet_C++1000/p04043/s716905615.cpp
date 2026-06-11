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
    int i,j,t,n,m,r;
    //cin>>t;
    //while(t--){
     int a[3];
     for(i=0;i<3;i++)cin>>a[i];
     sort(a,a+3); 
     if(a[0]==5 && a[1]==5 && a[2]==7)cout<<"YES"<<endl;
     else cout<<"NO"<<endl;
    //}
 return 0;
}

