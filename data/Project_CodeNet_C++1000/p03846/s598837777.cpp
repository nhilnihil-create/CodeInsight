#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> // Common file  
#include <ext/pb_ds/tree_policy.hpp>  
#include <functional> // for less
using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;

#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    std::cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');std::cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#define rep(i,a,n)    for(int i=a; i<=n; ++i)
#define rep1(i,a,n)   for(int i=a; i>=n; --i)
#define pb            push_back
#define mp            make_pair
#define int           long long
#define fr            first
#define sc            second
#define vc            vector
#define sz(v)         (int)v.size()
#define all(x)        (x).begin(),(x).end()
#define rall(x)       (x).rbegin(),(x).rend()
#define N             (int)(1e6+5)
#define M             1000000007
#define MM            998244353
#define PI            3.14159265358979
#define INF           1000000000000000

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef map<int,int> mii;

int n,m,ans; string str;

int pw(int a,int b,int p){
    if(b==0)return 1;
    int t=pw(a,b/2,p);
    if(b%2)return (((a*t)%p)*t)%p;
    else return ((t*t)%p);
}
int solve(){
    cin>>n;
    int a[n]; rep(i,0,n-1) cin>>a[i];
    sort(a,a+n);
    if(n%2){
        if(a[0]==0){
            int t=2;
            for (int i = 1; i < n; i+=2)
            {
                if(a[i]==a[i+1]&&a[i]==t){
                    t+=2;
                }
                else{
                    cout<<0;
                    return 0;
                }
            }
        }
        else{
            cout<<0;
            return 0;
        }
    }
    else{
        int t=1;
        for (int i = 0; i < n; i+=2)
        {
            if(a[i]==a[i+1]&&a[i]==t){
                t+=2;
            }
            else{
                cout<<0;
                return 0;
            }
        }
    }
    cout<<pw(2,n/2,M);
    return 0;
}

signed main() {
    ios::sync_with_stdio(0);
    //std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
}