#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> V;
#define rep(i,e) for(ll i=0;i<e;i++ )
typedef pair<ll,ll> P;
const ll mod = 1e9+7;
const ll INF = INT64_MAX;
ll i;



int main(){
   string A,B,C;
   cin>>A>>B>>C;
   if(A.at(A.length()-1)==B.at(0)&&B.at(B.length()-1)==C.at(0))cout<<"YES";
   else cout<<"NO";
   cout<<endl;
}
