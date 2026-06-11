#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <set>
#include <math.h>
#include <map>
using namespace std;
static const int INF = 1e9+7;
// 型定義
typedef long long ll;
typedef pair<ll, ll> P;

#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, a, b) for (int i =a; i < b; i++)
#define all(a) a.begin(), a.end()
#define PI 3.14159265359

int main(){
    int n, l; cin >> n >> l;
    vector<string>s(n);
    rep(i, n){
        cin >> s[i];
    }
    sort(all(s));
    rep(i, n){
        cout << s[i];
    }
    cout << endl;
    return 0;
}   
