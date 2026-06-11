#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<bitset>
#include<deque>
#include<functional>
#include<iterator>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<utility>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define a first
#define b second
#define sz(x) (ll)((x).size())
#define pb push_back
#define mp make_pair
#define bg begin()
#define ed end()
#define all(x) (x).bg,(x).ed
#define rep(i,n) for(ll i=0;i<(n);i++)
#define rep1(i,n) for(ll i=1;i<=(n);i++)
#define rrep(i,n) for(ll i=(n)-1;i>=0;i--)
#define rrep1(i,n) for(ll i=(n);i>=1;i--)
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
const ll MOD=1000000007;
const ll INF=1000000000000000;
template<class T> inline bool chmin(T& a, T b){if(a>b){a=b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b){if(a<b){a=b;return true;}return false;}
ll maxx(ll x,ll y,ll z){return max(max(x,y),z);}
ll minn(ll x,ll y,ll z){return min(min(x,y),z);}
ll gcd(ll x,ll y){if(x%y==0) return y;else return gcd(y,x%y);}
ll lcm(ll x,ll y){return x*(y/gcd(x,y));}
ll digsz(ll x){if(x==0) return 1;else{ll ans=0;while(x){x/=10;ans++;}return ans;}}
ll digsum(ll x){ll sum=0;while(x){sum+=x%10;x/=10;}return sum;}
vector<ll> pw2(62,1);vector<ll> pw10(19,1);

vector<ll> vectorprime(ll x){
    vector<bool> is_prime(x+1);
    vector<ll> prime;
    rep(i,x+1) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    for(ll i=2;i<=x;i++){
        if(is_prime[i]){
            prime.pb(i);
        }
        for(int j=i*2;j<=x;j+=i) is_prime[j]=false;
    }
    return prime;
}
map<ll,ll> prime_factor(ll x){
    map<ll,ll> m;
    ll sq=(ll)sqrt(x) + 1;
    vector<ll> v_prime=vectorprime(sq);
    
    ll tmp=x;
    rep(i,sz(v_prime)){
        ll count=0;
        while(tmp % v_prime[i] == 0){
            tmp /= v_prime[i];
            count++;
        }
        if(count != 0) m[v_prime[i]]=count;
        if(tmp==1) break;
    }
    
    if(tmp != 1) m[tmp]=1;
    return m;
}

int main(){
    {rep1(i,61) pw2[i]=2*pw2[i-1];}
    {rep1(i,18) pw10[i]=10*pw10[i-1];}
    
    ll N,K; cin>>N>>K;
    map<ll,ll> m;
    rep(i,N){
        ll A,B; cin>>A>>B;
        m[A]+=B;
    }
    ll tmp=0;
    for(auto it=m.bg;it!=m.ed;it++){
        if(K<=tmp+it->b){
            cout<<it->a<<endl;
            return 0;
        }
        else tmp+=it->b;
    }
}

