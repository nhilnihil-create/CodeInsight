#include <iostream>
using namespace std;
int main() {
    string s;
    cin >> s;
    int n = (int)(s.length());
    for (int i=1; i<n/2; i++) {
        string sub = s.substr(0, n/2-i);
        sub += sub;
        if (s.find(sub) != string::npos) {
            cout << n-2*i << endl;
            return 0;
        }
    }
}