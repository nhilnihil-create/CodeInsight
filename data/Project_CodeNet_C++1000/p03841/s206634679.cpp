#define ONLINE_JUDGE
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> pl;
typedef vector<pl> vp;
const ll INF=1001001001;
const ll LINF=1001001001001001001;
const ll D4[]={0,1,0,-1,0};
const ll D8[]={0,1,1,0,-1,-1,1,-1,0};
#define _overload3(_1,_2,_3,name,...) name
#define _rep2(i,n) for(ll i=0;i<(n);++i)
#define _rep3(i,a,b) for(ll i=(a);i<(b);++i)
#define rep(...) _overload3(__VA_ARGS__,_rep3,_rep2)(__VA_ARGS__)
#define _repe2(i,n) for(ll i=0;i<=(n);++i)
#define _repe3(i,a,b) for(ll i=(a);i<=(b);++i)
#define repe(...) _overload3(__VA_ARGS__,_repe3,_repe2)(__VA_ARGS__)
#define _rrep2(i,n) for(ll i=(n)-1;i>=0;i--)
#define _rrep3(i,a,b) for(ll i=(b)-1;i>=(a);i--)
#define rrep(...) _overload3(__VA_ARGS__,_rrep3,_rrep2)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()
template<class T>
bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>
bool chmin(T &a,const T &b){if(b<a){a=b;return 1;}return 0;}
template<class T>
using pq=priority_queue<T,vector<T>,greater<T>>;
const string YES = "Yes";
const string NO = "No";

ll N;
vl x;

void solve();

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N;
    x = vl(N);
    for(int i = 0; i < N; ++i){
        cin >> x[i];
    }
    solve();
}

// 1 ≤ N ≤ 500
// 1 ≤ x_i ≤ N^2
// x_i はすべて相異なる。

// ll N, vl x
// 条件をすべて満たす数列 a が存在しないならば、No を出力せよ。存在するならば、1 行目に Yes を出力し、2 行目に a を空白区切りで出力せよ。
void solve(){
    vl a(N*N,-1);
    rep(i,N)a[x[i]-1]=i+1;

    queue<ll> reserved;
    rep(i,N*N){
        if(a[i]!=-1)rep(j,1,a[i])reserved.push(a[i]);
    }

    vl ans(N*N);
    vl used(N+1);
    queue<ll> waiting;
    rep(i,N*N){
        if(a[i]==-1){
            if(reserved.size()){
                ll x=reserved.front();reserved.pop();
                if(used[x]){
                    cout<<NO<<endl;
                    return;
                }
                ans[i]=x;
            }else{
                if(waiting.empty()){
                    cout<<NO<<endl;
                    return;
                }
                ll x=waiting.front();waiting.pop();
                ans[i]=x;
            }
        }else{
            ans[i]=a[i];
            used[a[i]]=true;
            rep(j,N-a[i])waiting.push(a[i]);
        }
    }
    cout<<YES<<endl;
    rep(i,N*N){
        if(i>0)cout<<' ';
        cout<<ans[i];
    }
    cout<<endl;
}
