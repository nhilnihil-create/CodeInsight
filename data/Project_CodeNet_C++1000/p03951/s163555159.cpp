#include <iostream>
using namespace std;
int main() {
    int n;
    string s, t;
    cin >> n >> s >> t;
    int cnt = 0;
    string subs;
    for(int i=0; i<n; i++) {
        subs = t.substr(0, n-i);
        if (s.find(subs) == i) {
            cnt = n-i;
            break;
        }
    }
    cout << 2*n - cnt << endl;
}
