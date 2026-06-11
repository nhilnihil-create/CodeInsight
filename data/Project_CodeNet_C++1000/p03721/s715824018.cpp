#include "bits/stdc++.h"
#define all(v) v.begin(),v.end()
#define sz(x) (int)x.size()
#define endl "\n"
#define ld long double
using namespace std;
typedef long long int ll;
#ifdef ONLINE_JUDGE
#define debug(...)
#else
#define debug(...) cerr<<__LINE__ <<"::"<< "[" << #__VA_ARGS__ << "]->",debug_out(__VA_ARGS__)
#endif
void debug_out(){cerr << endl;} 
template <typename Head,typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr<<" "<<to_string(H);
  debug_out(T...);
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout<<fixed<<setprecision(2);
    int n;ll k;cin>>n>>k;
    map<int,ll>mp;
    for(int i=0,x,y;i<n;++i){
        cin>>x>>y;
        mp[x]+=ll(y);
    }
    for(auto x:mp){
        if(x.second<k){
            k-=x.second;
        }
        else{
            cout<<x.first<<endl;return 0;
        }
    }

}