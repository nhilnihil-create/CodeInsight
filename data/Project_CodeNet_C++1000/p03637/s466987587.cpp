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
    int n, val;
    cin >> n;
    int four = 0, not_two = 0;
    for(int i = 0; i < n; i++) {
        cin >> val;
        if (val % 4 == 0)
            four += 1;
        else if (val % 2 != 0)
            not_two += 1;
    }
    int thres = 0;
    if (four + not_two == n)
        thres = -1;
    if (four - not_two >= thres)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}


