#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    int  s = 0;
    vector<int>v;
    for (int i = 0; i < t; i++) {
      int x;
      cin >> x;
      v.push_back(x);
      s += x;
    }
    sort(v.begin(), v.end());
    if( s % 10 != 0) {
        cout << s << endl;
        return 0;
    }
    for (int i = 0; i < t; i++) {
        s = s - v[i];
        if(s % 10 != 0) {
            cout << s << endl;
            return 0;
        }
        else {
            s = s + v[i];
        }
    }
    cout << 0 << endl;
    return 0;
}
