#include <iostream>
#include <iomanip>
#include<vector>
#include <algorithm>
#include <queue>
#include<string>
#include <map>
#include <cmath>
#include <deque>
#include <list>
#include <stack>
#include <queue>
#include <utility>
#include <set>
#include <bitset>
typedef long long ll;
typedef long double ld;
#define PI  3.14159265358979323846

#define REP(i,s,n)for(ll i=s;i<(n);++i)
#define rep(i,n) REP(i,0,n)
using namespace std;




int main() {
    ll K, S;
    cin >> K >> S;
    ll counter = 0;
     rep(X,K+1) {
        rep(Y,K+1) {
            ll Z = S - X - Y;
            if (0<=Z&&Z<=K) {
                counter++;
            }
        }
    }
    cout << counter << endl;
    return 0;
}