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
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }
ll N;
string s;
vll animal;
//* sheep 0, wolf 1
bool check(ll a0, ll a1){
    
    animal[0] = a0; animal[1] = a1;
    for(ll i = 2; i < N; i++){
        if(animal[i-1]){ //* i-1 is wolf
            if(s[i-1]=='o')
                animal[i] = 1 - animal[i-2];
            else
                animal[i] = animal[i-2];
        }
        else{//* i-1 is sheep always true
            if(s[i-1]=='o')
                animal[i] = animal[i-2];
            else
                animal[i] = 1 - animal[i-2];
        }
    }
    //* check i=0
    if(animal[0]){//* 0 is wolf
        if(s[0] == 'o' && animal[N-1] == animal[1])
            return false;
        if(s[0] == 'x' && animal[N-1] != animal[1])
            return false;
    }else{
        if(s[0] == 'o' && animal[N-1] != animal[1])
            return false;
        if(s[0] == 'x' && animal[N-1] == animal[1])
            return false;
    }
    //* check i=N-1
    if(animal[N-1]){//* 0 is wolf
        if(s[N-1] == 'o' && animal[N-2] == animal[0])
            return false;
        if(s[N-1] == 'x' && animal[N-2] != animal[0])
            return false;
    }else{
        if(s[N-1] == 'o' && animal[N-2] != animal[0])
            return false;
        if(s[N-1] == 'x' && animal[N-2] == animal[0])
            return false;
    }
    return true;
}

int main(){
    scanf("%lld",&N);
    std::cin >> s;
    animal.resize(N, 0);
    bool isGood = false;
    isGood = check(0, 0);
    if(!isGood) isGood = check(0, 1);
    if(!isGood) isGood = check(1, 0);
    if(!isGood) isGood = check(1, 1);

    if(!isGood) cout<<-1<<endl;
    else{
        REP(i, N){
            if(animal[i]) cout<<"W";
            else cout<<"S";
        }
        cout<<endl;
    }

    return 0;
}
