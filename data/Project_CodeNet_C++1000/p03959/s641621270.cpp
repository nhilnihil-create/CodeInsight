#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <cstring>
#include <queue>
#include <stack>
#include <cmath>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <iostream>
#include <random>
#include <map>
#include <iomanip>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cassert>
#include <fstream>
#include <unordered_map>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <bitset>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using qll = queue<ll>;
using vb = vector<bool>;
using mll = map<ll, ll>;
using sll = stack<ll>;
#define REP(i,n) for(ll i(0);(i)<(n);(i)++)
#define rep(i,n) for(ll i(0);(i)<(n);(i)++)
#define ALL(a) a.begin(), a.end()
#define elnd endl //* missspell check
const ll INF=1LL<<60;

const long long MOD = 1000000007;

void solve(long long N, std::vector<long long> T, std::vector<long long> A){
    if(N == 1){
        if(T[0]==A[0]){
            cout << 1 << endl;
        }
        else{
            cout << 0 << endl;
        }
        return;
    }

    vector<pll> p(N, pll(0, INF));
    p[0].first = T[0]; p[0].second = T[0]+1;
    p[N-1].first = A[N-1]; p[N-1].second = A[N-1]+1;
    for(ll i=1; i< N; i++){
        if(T[i]==T[i-1]){
            p[i] = make_pair(max(p[i].first, 1LL), min(p[i].second, T[i]+1));
            if(p[i].first >= p[i].second){
                cout << 0 << endl;
                return;
            }
        }
        else{
            p[i] = make_pair(max(p[i].first,T[i]), min(p[i].second, T[i]+1));
            if(p[i].first >= p[i].second){
                cout << 0 << endl;
                return;
            }
        }
    }
    for(ll i= N-2; i>=0; i--){
        if(A[i]==A[i+1]){
            p[i] = make_pair(max(p[i].first, 1LL), min(p[i].second, A[i]+1));
            if(p[i].first >= p[i].second){
                cout << 0 << endl;
                return;
            }
        }
        else{ //* A[i] > A[i+1]
            p[i] = make_pair(max(p[i].first,A[i]), min(p[i].second, A[i]+1));
            if(p[i].first >= p[i].second){
                cout << 0 << endl;
                return;
            }
        }
    }
    ll res = 1;
    REP(i, N){
        res = (res * (p[i].second-p[i].first)) % MOD;
    }
    cout << res << endl;
    
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> T(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&T[i]);
    }
    std::vector<long long> A(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&A[i]);
    }
    solve(N, std::move(T), std::move(A));
    return 0;
}
