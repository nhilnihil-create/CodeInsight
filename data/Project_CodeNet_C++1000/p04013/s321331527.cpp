#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <iterator>
#include <iomanip>
#include <climits>
using namespace std; 
#define ll long long int


int main(){
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    vector<vector<ll> > d(n + 1, vector<ll>(50*50+1));

    d[0][0] = 1;

    for(int i = 0; i < n; ++i){
        for(int j = i; j >= 0; --j){
            for(int x = 0; x + a[i] <= 50*50; ++x){
                d[j + 1][x + a[i]] += d[j][x];
            }
        }
    }
    ll ans = 0;
    for(int i = 1; i <= n; ++i){
        ans += d[i][k * i];
    }
    cout << ans;
}
