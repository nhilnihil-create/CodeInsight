#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define vec_input(v) for(auto it=v.begin();it!=v.end();it++){cin>>*it;}
#define vec_output(v) for(auto it=v.begin();it!=v.end();it++){if(it!=v.begin())cout<<" ";cout<<*it;}cout<<endl;
#define vec_debug(v) for(auto it=v.begin();it!=v.end();it++){cerr<<*it<<" ";}cerr<<endl;
#define yn(ans) cout<<(ans?"Yes":"No")<<endl
#define YN(ans) cout<<(ans?"YES":"NO")<<endl
#define umap unordered_map
#define uset unordered_set
using namespace std;
using ll = long long;
template <typename T>T digitsum(T n);
template <typename T>bool isPrime(T n);
template <typename T>vector<pair<T, T>> prime_factor(T n);
long long int intpow(long long int,long long int);
template <typename T>T intlog(T);
long long int combination(long long int,long long int);
long long int arith_sum1(long long int,long long int,long long int);
long long int arith_sum2(long long int,long long int,long long int);
long long int series_sum(long long int);

/*int main(){
    int a;
    cin>>a;
    cout<<1<<" "<<a<<endl;
}*/

/*int main(){
    int t,a,b,sum;
    cin>>t;
    rep(l,t){
        cin>>a>>b;
        vector<int> vec(a);
        sum=0;
        rep(i,a){
            cin>>vec[i];
            sum+=vec[i];
        }
        cout<<(b<sum?b:sum)<<endl;
    }
}*/

int main(){
    ll n,k,a,b;
    set<ll> set;
    umap<ll,ll> map;
    cin>>n>>k;
    rep(l,n){
        scanf("%lld %lld",&a,&b);
        if(set.count(a)){
            map[a]+=b;
        }else{
            set.insert(a);
            map[a]=b;
        }
    }
    ll hikaku=0,ans;
    for(auto value:set){
        hikaku+=map[value];
        if(k<=hikaku){
            ans=value;
            break;
        }
    }
    cout<<ans<<endl;
}