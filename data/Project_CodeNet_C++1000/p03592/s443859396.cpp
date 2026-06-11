// CF2017B.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main()
{
    int n, m,k;
    cin >> n >> m>>k;
    bool ok = false;

    for(int i=0;i<=n;i++) {
        for(int j=0;j<=m;j++) {
            if (i * (m - j) + j * (n - i) == k) {
                ok = true;
                break;
            }
        }
    }
    if (ok) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    return 0;
}
