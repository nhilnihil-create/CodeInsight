#include <bits/stdc++.h>
using namespace std;

int main() {
    int result = 0;
    int n, buf = 0;
    string s;
    cin >> n >> s;
    
    for(int i = 0; i < n; i++) {
        if (s[i] == 'I') {
            buf++;
        }
        else {
            buf--;
        }
        result = max(buf,result);
    }
    
    cout << result << endl;
}
