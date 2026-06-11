#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define cinf(n,x) for(int i=0;i<(n);i++)cin>>x[i];
#define max3(a,b,c) max(max(a,b),c)
#define min3(a,b,c) min(min(a,b),c)
#define ft first
#define sc second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(v) (v).begin(),(v).end()
#define mod 1000000007
using namespace std;
typedef long long ll;
template<class T> using V=vector<T>;
using Graph = vector<vector<int>>;
using P=pair<int,int>;
typedef unsigned long long ull;
typedef long double ldouble;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

signed main(){
    int n,m,k;
    cin>>n>>m>>k;
    bool ok=0;
    for(int i=0;i<=n;i++){
        int cnt=i;
        int sum=m*i;
        if(sum==k){
            ok=1;
            break;
        }
        for(int j=0;j<=m;j++){
            sum+=n-cnt;
            sum-=cnt;
            if(sum==k){
                ok=1;
                break;
            }
        }
    }
    cout<<(ok?"Yes":"No")<<endl;
}