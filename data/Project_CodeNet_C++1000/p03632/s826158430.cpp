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
    int a, b, c, d; cin >> a >> b >> c >> d;
    int result[101] = {};
    repr(i, a, b+1) result[i]++;
    repr(i, c, d+1) result[i]++;
    int length = 0;
    repr(i, 0, 102){
        if(result[i] == 2) length++;
    }
    if(length != 0){
        cout << length-1 << endl;
    }else{
        cout << length << endl;
    }

    return 0;
}
