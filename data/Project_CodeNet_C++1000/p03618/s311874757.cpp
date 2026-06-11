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


void solve(std::string A){
    map<char, ll> rec;
    REP(i, A.length()){
        rec[A[i]]++;
    }
    vll cnt;
    for(auto x: rec){
        cnt.push_back(x.second);
    }
    ll M = cnt.size();
    ll ans = 0;
    REP(i, M){
        for(ll j = i+1; j < M; j++){
            ans += cnt[i] * cnt[j];
        }
    }
    cout<<ans+1<<endl;
}

int main(){
    std::string A;
    std::cin >> A;
    solve(A);
    return 0;
}
