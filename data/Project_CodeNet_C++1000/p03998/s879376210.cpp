#include <bits/stdc++.h>
#include <iomanip>
#include <math.h>
#define rep(i,x) for(ll i = 0;i<x;i++)
#define all(a) (a).begin(),(a).end()
using ll = long long;
using ld = long double;
using namespace std;
using dou = double;
const ll INF = 1LL << 60;
const ll mod = 1000000007;
typedef pair<ll,ll> P;
using graph = vector<vector<ll>>;
template<class T> inline bool chmax(T& a, T b){if(a < b){a = b; return true;}return false;}
template<class T> inline bool chmin(T& a, T b){if(a > b){a = b; return true;}return false;}
ll gcd(ll a,ll b){
    if(a < b)swap(a,b);
    if(a % b == 0)return b;
    else return gcd(b,a%b);
}
bool isp(ll n){
    bool res = true;
    if(n == 1)return false;
    else{
        for(ll i = 2;i * i <= n;i++){
            if(n % i == 0){
                res = false;
                break;
            }
        }
        return res;
    }
}
//printf("%.10f\n", N);
/*
ll fibo(ll n){
    if(memo[n] != 0)return memo[n];
    if(n <= 1)return n;
    else return memo[n] = fibo(n - 1)+ fibo(n - 2);
}*/
/*  vector<ll> vec = {1,2,5,6,8,9,10};
    cout << binary_search(all(vec),5) << endl; -> true*/
/*
    vector<ll> vec = {1,2,5,6,8,9,10};
    auto n = upper_bound(all(vec),4);
    cout << *n << endl; -> 5*/
int main(){
    string S,T,U;
    cin >> S >> T >> U;
    char now;
    now = 'a';
    ll s = S.size(),t = T.size(),u = U.size();
    ll cnts = 0,cntt = 0,cntu = 0;
    char ans = 'A';
    while(true){//s-1=cnts -> break
        if(now == 'a'){
            if(cnts == s)break;
            else {
                now = S[cnts];
                cnts++;
            }
        }
        else if(now == 'b'){
            if(cntt == t){
                ans ='B';
                break;
            }
            else {
                now = T[cntt];
                cntt++;
            }
        }
        else{
            if(cntu == u){
                ans ='C';
                break;
            }
            else {
                now = U[cntu];
                cntu++;
        }
    }
//    cout << cnts <<" " << cntt << " " << cntu << endl;
}
    cout << ans << endl;
}