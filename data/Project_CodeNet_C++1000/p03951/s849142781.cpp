#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    string s,t;
    cin >> N >> s >> t;
    for(int i = N; i >= 1; i--) {
        string x = s.substr(N-i,N);
        string y = t.substr(0,i);
        if(x == y) {
            cout << N*2-i << endl;
            return 0;
        }
    }
    cout << N*2 << endl;
}
