#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
int main() {
    string x;
    cin >> x;
    int s_count = 0;
    int ret = 0;
    for (int i = 0; i < x.length(); i++) {
        if (x[i] == 'T') {
            if (s_count == 0) {
                ret++;
            }
            else {
                s_count--;
            }
        }
        else {
            s_count++;
        }
    }
    cout << ret + s_count << endl;
    return 0;
}