#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <set>
#include <math.h>
#include <map>
#include <stack>
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
    int n; cin >> n;
    vector<int> t(n);
    rep(i, n) cin >> t[i];

    int m; cin >> m;
    vector<int> p(m);
    vector<int> x(m);
    rep(i, m) cin >> p[i] >> x[i];
    int result[101] = {};

    rep(i, m){
        rep(j, n){
            if(j == p[i]-1){
                result[i] += x[i];
            }else{
                result[i] += t[j];  
            }
        }
        cout << result[i] << endl;
    }
    
    return 0;
}
