#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define vec_input(v) for(auto it=v.begin();it!=v.end();it++){cin>>*it;}
#define vec_output(v) for(auto it=v.begin();it!=v.end();it++){if(it!=v.begin())cout<<" ";cout<<*it;}cout<<endl;
#define vec_debug(v) for(auto it=v.begin();it!=v.end();it++){cerr<<*it<<" ";}cerr<<endl;
#define yn(ans) cout<<(ans?"Yes":"No")<<endl
#define YN(ans) cout<<(ans?"YES":"NO")<<endl
using namespace std;
using ll = long long;
template <typename T>T digitsum(T n);
template <typename T>bool isPrime(T n);
template <typename T>vector<pair<T, T>> prime_factor(T n);
long long int intpow(long long int,long long int);
template <typename T>T intlog(T);
long long int combination(long long int,long long int);
long long int series_sum(long long int);

int main(){
    ll n;
    cin>>n;
    vector<ll> vec(n);
    vec_input(vec);
    list<ll> list;
    rep(i,n){
        if(i%2==0){
            list.push_back(vec[i]);
        }else{
            list.push_front(vec[i]);
        }
    }
    if(n%2==1)reverse(all(list));
    vec_output(list);
}