#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
    int N, a;
    cin >> N;
    vector<int> col(9);
    int cnt = 0;
    int Min, Max;
    rep(i,N) {
        cin >> a;
        if (a / 400 >= 8) ++col.at(8);
        else ++col.at(a/400);
    }
    rep(i,8) if (col.at(i)) ++cnt;
    if (cnt == 0) Min = 1;
    else Min = cnt;
    Max = cnt+col.at(8);
    cout << Min << " " << Max << endl;
}

