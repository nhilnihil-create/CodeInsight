#include                        <bits/stdc++.h>
#include                        <ext/pb_ds/assoc_container.hpp>
#define lb                      lower_bound
#define ub                      upper_bound
#define pb(x)                   push_back(x)
#define ook(x)                  order_of_key(x)
#define fbo(x)                  find_by_order(x)
#define all(x)                  (x).begin(),(x).end()
#define FOR(i,a,b)              for(int i = a; i<=b; i++)
#define REP(i,a,b)              for(int i = a; i<b;  i++)
#define dbg(a)                  cout<<#a <<" --> "<<(a)<<endl;
#define TT                      int TC;  cin>>TC;  while(TC--)
#define read                    freopen("input.txt","r",stdin)
#define write                   freopen("output.txt","w",stdout)
#define set(x)                  tree<x,null_type,less<x>,rb_tree_tag,tree_order_statistics_node_update>
using                           namespace std;
using                           namespace __gnu_pbds;
typedef                         long long ll;
typedef                         pair<ll,ll> pll;
typedef                         pair<int,int> pii;

#define mx 200002
ll ar[27][mx];


main(){
//read;

string s;
cin>>s;
s = " " + s;
int n = s.size();
for(int i = 1; i<n; i++){
    int x = s[i] - 'a';
    ar[x][i]++;
    for(int j = 0; j<26; j++)
        ar[j][i]+=ar[j][i-1];
}

ll ans = 1;
for(ll i = 1; i<n; i++){
    int x = s[i] - 'a',b = 0;
    for(int j = 0; j<26; j++){
        if(j==x)    continue;
        b+=ar[j][n-1] - ar[j][i-1];
    }
    ans+=b;
}
cout<<ans;
return 0;
}
