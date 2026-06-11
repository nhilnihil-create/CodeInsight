//#pragma GCC target("avx2")
//#pragma GCC optimization("O3")
//#pragma GCC optimization("unroll-loops")
//assert(q==w) если q!=w --> runtime error
#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define ub upper_bound
#define lb lower_bound
#define bit __builtin_popcount
#define memset(x) memset(x,0,sizeof(x))

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<vector<int>> matrix;

inline void boost(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

const ll maxn=2e5+123;
const ll inf=1e9+123;
const ll linf=1e18+123;
const ll mod=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
int dx[8]={0,1,-1,0,1,-1,1,-1};
int dy[8]={1,0,0,-1,1,1,-1,-1};
int a[maxn];
int main(){
    boost();
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    int mx=0,mn=inf;
    int x=0,y=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mx=max(mx,a[i]);
        mn=min(mn,a[i]);
    }
    if(mx-mn>=2){
        cout<<"No";
        return 0;
    }
    if(mx==mn){
        bool ok=1,ok1=1;
        for(int i=1;i<=n;i++){
            if(a[i]!=n-1){
                ok=0;
            }
            if(2*a[i]>n){
                ok1=0;
            }
        }
        if(ok==0 && ok1==0){
            cout<<"No";
            return 0;
        }
        cout<<"Yes";
        return 0;
    }
    for(int i=1;i<=n;i++){
        if(a[i]==mn){
            x++;
        }
        else{
            y++;
        }
    }
    if(x+1<=mx && mx<=x+y/2){
        cout<<"Yes";
        return 0;
    }
    cout<<"No";
    exit(0);
}
