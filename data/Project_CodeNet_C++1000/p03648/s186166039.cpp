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
#define enld endl //* missspell check
const ll INF = 1LL << 60;

void solve(long long K){
    if(K == 0){
        cout << 2 << endl;
        cout << "1 1" << endl;
    }
    else if( K <= 10){
        ll N = max(2LL, K+1);
        vll A(N, 0);
        A[0] = K * N;
        cout << N << endl;
        REP(i, N){
            cout << A[i] << " ";
        }
        cout<<endl;
    }
    else{
        ll N = min(50LL, K-1);
        
        ll num_big = K / N;
        ll num_res = K % N;
        vll A(N, N - 1 + num_big);
        
        REP(i, num_res){
            A[i] += N - num_res + 1;
        }
        for(ll i = num_res; i < N; i++){
            A[i] -= num_res;
        }
        cout << N << endl;
        REP(i, N){
            cout << A[i] << " ";
        }
        cout<<endl;
    }



}

int main(){
    long long K;
    scanf("%lld",&K);
    solve(K);
    return 0;
}
