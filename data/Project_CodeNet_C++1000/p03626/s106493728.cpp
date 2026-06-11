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
#define MOD 1000000007

void solve(long long N, std::vector<std::string> S){
    ll res = 1;
    ll i=0, W = S[0].length(), type=0;
    while(i < W){
        if(S[0][i]==S[1][i]){//* type1
            if(type == 0){
                res = (res * 3) % MOD;
            }
            else if(type == 1){
                res = (res * 2) % MOD;
            }
            type = 1;
            i++;
        }
        else {
            if(type == 0){
                res = (res * 6) % MOD;
            }
            else if(type == 1){
                res = (res * 2) % MOD;
            }
            else{
                res = (res * 3) % MOD;
            }
            type = 2;
            i += 2;
        }
    }
    cout << res << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<std::string> S(2);
    for(int i = 0 ; i < 2 ; i++){
        std::cin >> S[i];
    }
    solve(N, std::move(S));
    return 0;
}
