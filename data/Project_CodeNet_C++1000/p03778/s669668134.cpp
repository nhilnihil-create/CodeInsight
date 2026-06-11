#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
#define endl "\n"
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();
// freopen("input.txt", "r", stdin);

int main() {
    int w, a, b;
    cin >> w >> a >> b;
    if (a > b) swap(a, b);
    cout << max(0, b-(a+w)) << endl;
    return 0;
}
