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
    string s; cin >> s;
    int alphabet[123] = {};
    rep(i, s.size()){
        alphabet[int(s[i])]++;
    }
    bool flg = true;
    repr(i, 97, 122){
        if(alphabet[i] > 1){
            flg = false;
            break;
        }
    }
    if(flg){
        cout << "yes" << endl;
    }else{
        cout << "no" << endl;
    }
        

    return 0;
}
