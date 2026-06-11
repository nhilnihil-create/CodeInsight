#include<bits/stdc++.h>
#define fastio     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define all(x)     (x).begin() , (x).end()
#define rep(i,a,b) for(int i=a;i<b;i++)
#define endl       '\n'
#define MAX        1000000
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
typedef long long int ll;
using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}


const ll mod = 1e9+7;
const double eps = 1e-9;
const double pi = acos(-1);


const int maxN=102;
int arr[maxN];
int n;

ll cost(int e) {
    ll c=0;
    for(int i=0;i<n;++i) {
        c+=(arr[i]-e)*(arr[i]-e);
    }
    return c;
}

void solve(){
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    ll ans=numeric_limits<ll>::max();
    for(int j=-100;j<=100;j++) {
        ans=min(ans,cost(j));
    }
    cout<<ans<<"\n";
}





int main(){
    fastio
    int test=1;
    while(test--)
        solve();
    return 0;
}
