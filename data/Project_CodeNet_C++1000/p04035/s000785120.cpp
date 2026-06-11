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

const string YES = "Possible";
const string NO = "Impossible";

void solve(long long N, long long L, std::vector<long long> a){
    bool isGood = false;
    ll i0;
    REP(i, N-1){
        if(a[i]+a[i+1]>= L){
            isGood = true;
            i0 = i;
            break;
        }
    }
    if(!isGood){
        cout << NO <<endl; return;
    }
    cout << YES <<endl;
    for(ll i=1; i<=i0; i++){
        cout << i <<endl;
    }
    for(ll i= N-1; i >= i0+2; i--){
        cout << i <<endl;
    }
    cout << i0+1<<endl;


}

int main(){
    long long N;
    scanf("%lld",&N);
    long long L;
    scanf("%lld",&L);
    std::vector<long long> a(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&a[i]);
    }
    solve(N, L, std::move(a));
    return 0;
}
