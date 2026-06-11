#include<iostream>
#include<cmath>
#include<vector>
#include<set>
#include<algorithm>
#include<tuple>
#include<utility>
#include<cctype>
#include<climits>
#include<map>
#include<queue>
#include<functional>
#include<stack>
#include<iomanip>
#include<sstream>
#include<bitset>

using namespace std;

#define REP(i,a,n) for(int i=a;i<n;++i)
#define REPL(i,a,n) for(ll i=a;i<n;++i)
#define RUP(a,b) ((a+b-1)/(b))
#define ENT "\n"
#define SORTVG(v) sort(v.begin(),v.end(),greater<>())
#define SORTV(v) sort(v.begin(),v.end())
#define ALL(v) (v).begin(),(v).end()
#define MOD 1000000007
#define INF LLONG_MAX/2

typedef long long ll;
typedef tuple<int,int,bool> Tb;
typedef pair<int,int> Pii;
typedef vector<int> Vi;

template<class T> void chmax(T& a, T b) {if(a < b){a=b;}}
template<class T> void chmin(T& a, T b) {if(a > b){a=b;}}
template<class T> void YesNo(T& a) {if(a){cout << "Yes" << ENT;}else{cout << "No" << ENT;}}
template<class T> void YESNO(T& a) {if(a){cout << "YES" << ENT;}else{cout << "NO" << ENT;}}


int atcoder(){
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n),b(n);
    REPL(i,0,n) cin>>a[i]>>b[i];
    
    stringstream ss;
    ss << bitset<30>(k);
    string s = ss.str();
    
    vector<ll> check;
    check.push_back(k);
    REP(i,0,s.length()){
        if(s[i]=='1'){
            string t=s;
            t[i]='0';
            REP(j,i+1,s.length()) t[j]='1';
            ll tmp=stoll(t,0,2);
            check.push_back(tmp);
        }
    }
    
    ll ans=0;
    REP(i,0,check.size()){
        ll tmp=0;
        REP(j,0,n) if((check[i] | a[j]) == check[i]) tmp+=b[j];
        chmax(ans,tmp);
    }
    cout<<ans<<ENT;
    return 0;
}


signed main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    atcoder();
    return 0;
}
