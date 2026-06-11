#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back
#define mk make_pair
#define v_sort(x) sort(x.begin(),x.end())
#define v_gsort(x) sort(x.begin(),x.end(),greater<int>())
#define PI 3.14159265
#define MOD 998244353

using namespace std;

void Solve(){
   int n,m,k;
   cin>>n>>m>>k;
   for(int a=0;a<=m;a++){
     for(int b=0;b<=n;b++){
       if(k==a*n+b*m-2*a*b) {cout<<"Yes\n";return;}
     }
   }
   cout<<"No\n";
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t=1;
//  cin>>t;
  while(t--){
      Solve();
  }
  return 0;
}
