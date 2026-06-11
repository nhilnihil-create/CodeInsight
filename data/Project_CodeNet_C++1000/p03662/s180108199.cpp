#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <queue>
#include <cmath>
#include <complex> // complex<double> a(1.2 , 2.3);// real(): 1.2, imag()2.3
using namespace std;

#define MOD 1000000007
#define ll long long
#define ld long double
#define FOR(i,a,b) for(ll i=(ll)a;i<(ll)b;i++)
#define rep(i,n) FOR(i,0,n)
#define pb push_back
#define mp make_pair
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define rmsame(a) sort(all(a)),a.erase(unique(all(a)), a.end())
#define rmvector(a,b) rep(i,a.size())rep(j,b.size())if(a[i]==b[j]){a.erase(a.begin()+i);i--;break;}
#define pq_pair_tB priority_queue <pair<ll,ll>, vector<pair<ll,ll> > , greater<pair<ll,ll> > >
#define pq_pair_ts priority_queue <pair<ll,ll> > //第二成分の大きさが関係ない
template<typename X> bool exist(vector<X> vec, X item){return find(all(vec), item)!=vec.end();}
ll gcd(ll a, ll b){if(b==0)return a;return gcd(b,a%b);}
ll lcm(ll a, ll b){return a/gcd(a,b)*b;}

ll N ;
int check[100005];
map<ll, vector<ll> > tree;
vector<ll> Fennec, Snuke;

void cal(){
    ll a = Fennec.size();
    ll b = Snuke.size();
    if(a+b == 0) return ;
    
    cerr << "s  aaa" << endl;
    rep(i,a){
        ll now = Fennec[0];
        cerr << now << endl;
        Fennec.erase(Fennec.begin()+0);
        rep(j, tree[now].size()){
            if(check[tree[now][j]] != 0) continue;
            check[tree[now][j]] = 1;
            Fennec.pb(tree[now][j]);
        }
    }
    cerr << "t  aaa" << endl;

    rep(i,b){
        ll now = Snuke[0];
        Snuke.erase(Snuke.begin()+0);
        rep(j, tree[now].size()){
            if(check[tree[now][j]] != 0) continue;
            check[tree[now][j]] = 2;
            Snuke.pb(tree[now][j]);
        }
    }


    cal();
    
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin >> N ;
    for(ll i = 1 ; i <= N ; i++){
        check[i] = 0;
    }
    
    rep(i,N-1){
        ll a, b;
        cin >> a >> b ;
        tree[a].pb(b);
        tree[b].pb(a);
    }
    
    Fennec.pb(1);
    Snuke.pb(N);
    check[1] = 1;
    check[N] = 2;
    
    cal();
    
    ll f = 0, s = 0;
    for(ll i = 1; i<= N ; i++){
        cerr << i << "----" << check[i] << endl;
        if(check[i] == 1) f++;
        if(check[i] == 2) s++;
    }
    cerr << f <<" " << s << endl;
    if(f > s) cout << "Fennec" << endl;
    else cout << "Snuke" << endl;
    
    //cout << fixed << setprecision(16) << ans << endl;
    return 0;
}
