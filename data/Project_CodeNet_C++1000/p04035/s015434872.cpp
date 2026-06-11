#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define cinf(n,x) for(int i=0;i<(n);i++)cin>>x[i];
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
using P=pair<ll,ll>;
typedef unsigned long long ull;
typedef long double ldouble;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//V,P(大文字)使用不可
//乗算の際にオーバーフローに注意せよ！！（適切にmodをとれ）
//制約をよく読め！

const ll INF=1e18;

signed main(){
    int n;
    ll L;
    cin>>n>>L;
    V<ll> a(n);
    cinf(n,a);
    bool ok=0;
    int last;
    rep(i,n-1){
        if(a[i]+a[i+1]>=L){
            ok=1;
            last=i+1;
            break;
        }
    }
    if(ok){
        cout<<"Possible"<<'\n';
        int m=1;
        while(m<last){
            printf("%d\n",m);
            m++;
        }
        m=n-1;
        while(m>last){
            printf("%d\n",m);
            m--;
        }
        
        printf("%d\n",last);
    }else printf("Impossible\n");
}