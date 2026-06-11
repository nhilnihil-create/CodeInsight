#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();
/*
12345671234567
 234566223456
  3456622345
   45662234
*/
int main() {
    int n, x;
    cin >> n >> x;
    if (x == 1 || x == n*2-1) {
        cout << "No" << endl;
    } else {
        vector<int> post;
        int n2 = n*2-1;
        cout << "Yes" << endl;
        for(int i = n; i < n*2-1; i++) {
            cout << (1+(x+i-1)%n2) << endl;
        }
        for(int i = 0; i < n; i++) {
            cout << (1+(x+i-1)%n2) << endl;
        }
    }
    return 0;
}


