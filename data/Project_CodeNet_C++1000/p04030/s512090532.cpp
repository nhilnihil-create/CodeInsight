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
    stack<char> result;
    rep(i,s.size()){
        if(s[i] == '0' || s[i] =='1'){
            result.push(s[i]);
        }else if(!result.empty()){
            result.pop();
        }
    }
    string ans = "";
    int len = result.size();
    rep(i,len){
        ans += result.top();
        result.pop();
    }
    reverse(all(ans));
    cout << ans << endl;

    return 0;
}
