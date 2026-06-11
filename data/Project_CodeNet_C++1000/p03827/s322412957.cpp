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
    string s; cin >> s;
    int x = 0;
    int max_x = 0;
    rep(i, n){
        if(s[i] == 'I'){
            x++;
        }else{
            x--;
        }
        if(x > max_x) max_x = x;

    }

    cout << max_x << endl;

    return 0;
}
