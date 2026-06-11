#include<algorithm>
#include<bitset>
#include<cmath>
#include<complex>
#include<deque>
#include<functional>
#include<iomanip>
#include<iostream>
#include<iterator>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<vector>

using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
#define ALL(x) (x).begin(),(x).end()
#define SIZE(x) ((ll)(x).size())
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
#define D()
#define INF 1000000000000
#define MOD 10000007
#define MAXR 100000
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define INITA(a,i,j,v) for(ll k=i;k<=j;k++){a[k]=v;}

int main() {
    string s; cin >> s;
    // dream, dreamer, erase, eraser

    ll cur = 0;
    ll solve = false;
    while (true) {
        if (s.substr(cur, 7) == "dreamer") {
            // 末尾のerがerase/eraser由来かを確かめる
            if (s.substr(cur+5, 5) == "erase") {
                cur += 5;
            } else {
                cur += 7;
            }
        } else if (s.substr(cur, 5) == "dream") {
            cur += 5;
        } else if (s.substr(cur, 6) == "eraser") {
            cur += 6;
        } else if (s.substr(cur, 5) == "erase") {
            cur += 5;
        } else if (cur == s.size()) {
            solve = true;
            break;
        } else {
            break;
        }
    }
    if (solve) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}