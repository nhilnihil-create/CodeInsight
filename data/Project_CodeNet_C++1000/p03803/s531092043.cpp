#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> V;
#define rep(cnt,e) for(ll cnt=0;cnt<e;cnt++ )
typedef pair<ll,ll> P;
const ll mod = 1e9+7;
const ll INF = INT64_MAX;

ll i,j,k;


int main(){
   ll A,B;
   cin>>A>>B;
   if(A==B)cout<<"Draw"<<endl;
   else if(A==1||A>B&&B!=1)cout<<"Alice"<<endl;
   else cout<<"Bob"<<endl;


}