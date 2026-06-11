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
    string a; cin >> a; queue<char> sa;
    rep(i, a.size()) sa.push(a[i]);
    string b; cin >> b; queue<char> sb; 
    rep(i, b.size()) sb.push(b[i]);
    string c; cin >> c; queue<char> sc;
    rep(i, c.size()) sc.push(c[i]);
    char turn='a';
    while(1){
        if(turn == 'a'){
            if(sa.empty()) break;
            turn = sa.front();
            sa.pop();
        }else if(turn == 'b'){
            if(sb.empty()) break;
            turn = sb.front();
            sb.pop();
        }else if(turn == 'c'){
            if(sc.empty()) break;
            turn = sc.front();
            sc.pop();
        }
    }
    cout << char(int(turn)-32) << endl;
    return 0;
}
