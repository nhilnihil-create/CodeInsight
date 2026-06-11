#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    int N, l, r;
    int count = 0;
    cin >> N;

    rep(i, N)
    {
        cin >> l;
        cin >> r;
        count += r - l + 1;

    }
    cout << count << endl;
    return 0;
}