#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();
// freopen("input.txt", "r", stdin);

int main() {
    int a, b;
    cin >> a >> b;
    if (a % 3 == 0 || b % 3 == 0 || (a+b) % 3 == 0)
        cout << "Possible" << endl;
    else
        cout << "Impossible" << endl;
    return 0;
}

