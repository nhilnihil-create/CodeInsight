#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s;
    int ans = 0, Ag = 0, Ap = 0;
    cin >> s;
    for (unsigned int i = 0; i < s.size(); i++) {
        if (s[i] == 'g') {
            if (Ap < Ag) {
                Ap++;
                ans++;
            } else {
                Ag++;
            }
        } else {
            if (Ap < Ag) {
                Ap++;
            } else {
                Ag++;
                ans--;
            }
        }
    }
    cout << ans << endl;
    return 0;
}