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



int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll N , T; cin >> N >> T;
    vector<ll> A;
    rep(i,N){
        ll inp; cin >> inp;
        A.pb(inp);
    }
    
    vector<pair<pair<ll,ll>, pair<ll,ll> > > ss;
    
    ll a = 1000000000,b = 1000000000;
    ll acnt = 1, bcnt = 1;
    rep(i,A.size()){
        if(A[i] < a){
            ss.pb(mp(mp(a,acnt), mp(b,bcnt)));
            a = A[i]; b = A[i];
            acnt = 1; bcnt = 1;
        }
        else if(A[i] == a) acnt ++;
        else if(A[i] > b) b = A[i];
        else if(A[i] == b) bcnt ++;
        
        if(i == A.size()-1)ss.pb(mp(mp(a,acnt), mp(b,bcnt)));
    }
    
    ll ans = 0;
    ll max_ans = 0;
    rep(i,ss.size()){
        a = ss[i].first.first;
        acnt = ss[i].first.second;
        b = ss[i].second.first;
        bcnt = ss[i].second.second;
        
        if(a == b) continue;
        if((b-a) > max_ans){
            max_ans = (b-a);
            ans = min(acnt, bcnt);
        }
        else if((b-a) == max_ans){ans += min(acnt,bcnt);}
        
    }
    cout << ans << endl;
    
    
    //cout << fixed << setprecision(16) << ans << endl;
    return 0;
}
