#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>
using namespace std;

#define next '\n'
#define sp " "
#define print(x) cout << (x)
#define println(x) cout << (x) << next
#define stop return(0)
#define rep(i, n) for(int (i) = (0); (i) < (n); (++i))
#define FOR(i, start, end) for(int (i) = (start); (i) < (end); (++i))
#define foreach(e, elem) for(auto& (e) : (elem))
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr)
#define size(s) (s).size()
#define all(vec) (vec).begin(), (vec).end()
#define pb(e) push_back(e);
using ll = long long;
using ull = unsigned long long;

vector<int> v;

int main() {
    int n;
    cin >> n;
    n *= 2;
    rep(i, n){
        int l;
        cin >> l;
        v.pb(l);
    }

    sort(all(v));

    int sum = 0;
    for(int i = 0; i < size(v); i += 2){
        sum += min(v[i], v[i + 1]);
    }

    println(sum);
}