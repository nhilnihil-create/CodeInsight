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
    int n, m, a, b;
    cin >> n >> m;
    vector<int> ball(n, 1);
    vector<int> red(n, 0);
    red[0] = 1;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        if (red[a-1] == 1) {
            red[b-1] = 1;
            if (ball[a-1] == 1)
                red[a-1] = 0;
        }
        ball[a-1] -= 1;
        ball[b-1] += 1;
    }
    cout << accumulate(red.begin(), red.end(), 0) << endl; 
    return 0;
}
