#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// グローバル変数
ll a, b, c;
const int max_val = 50000;

// 関数プロトタイプ
void input();
void solve();
bool check(int);

int main(void)
{
    input();
    solve();  
}

// 標準入力
void input() {
    cin >> a >> b >> c;
}

void solve() {
    int i = 0;
    for (; i < max_val;i++) {
        bool ca = check(a);
        bool cb = check(b);
        bool cc = check(c);
        if(!ca || !cb || !cc) {
            break;
        }
        if (ca && cb && cc) {
            ll tmpa = a / 2;
            ll tmpb = b / 2;
            ll tmpc = c / 2;
            a = tmpb + tmpc;
            b = tmpa + tmpc;
            c = tmpa + tmpb;
        }
    }
    if(i == max_val){
        i = -1;
    }
    cout << i << endl;
}

bool check(int n) {
    if(n%2 != 0) {
        return false;
    }
    return true;
}