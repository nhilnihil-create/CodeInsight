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
    int r, c;
    cin >> r >> c;
    string s(c+2, '#');
    cout << s << endl;
    for(int i = 0; i < r; i++) {
        string s2 = s;
        string s3;
        cin >> s3;
        for(int i = 0; i < c; i++)
            s2[i+1] = s3[i];
        cout << s2 << endl;
    }
    cout << s << endl;
    return 0;
}
