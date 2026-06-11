#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <math.h>
#include <utility>
#include <vector>
#include <map>
#include <unordered_map>
#include <cstdlib>
#define div1 1000000007
const long long INF = 1LL << 60;
using namespace std;
using ll = long long;
// a>b -> a==b;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
// a<b -> a==b;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

template <class T> void swap(T& a, T& b) { T t = std::move(a); a = std::move(b); b = std::move(t); }

// nのk乗をmで割った余り(n^k(mod m))を求める
ll pow_mod(ll n, ll k, ll m){
    if(k == 0){
        return 1;
    }
    else if(k % 2 == 1){
        return pow_mod(n, k-1, m) * n % m;
    }
    else{
        ll t = pow_mod(n, k/2, m);
        return t * t % m;
    }
}

int main(void)
{
    ll N, i, A[100001], C[100001], judge=1;

    cin >> N;

    for(i=0; i<=100000; i++){
        C[i] = 0;
    }

    for(i=1; i<=N; i++){
        cin >> A[i];
        C[A[i]]++;
    }

    if(C[0]!=1 && C[1]!=2){
        judge = 0;
    }
    else if(C[0]==1){
        for(i=0; i<=N; i++){
            if(i%2==0){
                if(i==0 && C[i]!=1) judge=0;
                else if(i!=0 && C[i]!=2) judge = 0;
            }
        }
    }
    else{
        for(i=0; i<=N; i++){
            if(i%2==1 && C[i]!=2) judge = 0;
        }
    }

    if(judge == 0){
        cout << 0 << endl;
    }

    else{
        cout << pow_mod(2,N/2,div1) << endl;
    }

    return 0;
}