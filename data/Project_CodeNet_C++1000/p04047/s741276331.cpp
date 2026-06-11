#include <bits/stdc++.h>
using namespace std;
#define ALL(a) (a).begin(),(a).end()
#define rALL(a) (a).rbegin(),(a).rend()
typedef pair<int, int> Pint;
typedef pair<int64_t, int64_t> Pll;
typedef int64_t ll;


int main() {
    int N, ans = 0;
    cin >> N;
    vector<int> L(2 * N);
    for (int i = 0; i < 2 * N; i++){
        cin >> L.at(i);
    }
    sort(ALL(L));
    for (int i = 0; i < 2 * N; i += 2){
        ans += L.at(i);
    }
    cout << ans << endl;
}
