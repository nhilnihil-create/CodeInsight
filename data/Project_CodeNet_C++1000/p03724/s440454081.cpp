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
using P=pair<int,int>;
typedef unsigned long long ull;
typedef long double ldouble;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

const ll INF=1e18;

int main(){
    int n,m;
    cin>>n>>m;
    V<int> a(m),b(m);
    V<int> c(n,0);
    rep(i,m){
        cin>>a[i]>>b[i];
        a[i]--;
        b[i]--;
        c[a[i]]++;
        c[b[i]]++;
    }
    bool ok=1;
    rep(i,n){
        if(c[i]%2==1) ok=0;
    }
    if(ok) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
//ペナルティ出しても焦らない　ACできると信じろ！！！
/*
V,P(大文字)使用不可
乗算の際にオーバーフローに注意せよ！(適切にmodをとれ)
制約をよく読め！
(全探索できるなら全探索しろ)
stringの計算量(扱い)注意
コーナー注意！(特に数値が小さいものについては要検証)
N行出力のときは'\n'
*/