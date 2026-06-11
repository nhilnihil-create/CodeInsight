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

int main(void)
{
    ll N, i;
    cin >> N;

    vector<pair<ll, ll>> AB(N);
    
    for(i=0; i<N; i++){
        cin >> AB[i].first >> AB[i].second;
    }

    sort(AB.begin(), AB.end());

    cout << AB[N-1].first+AB[N-1].second << endl;

    return 0;
}