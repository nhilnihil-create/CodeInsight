#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int N;
    int64_t a;
    int64_t mod4 = 0;
    int64_t odd = 0;
    int64_t even = 0;

    cin >> N;

    for(int i=0;i<N;i++) {
        cin >> a;
        if(a % 2) {
            odd++;
        } else {
            if(a % 4) {
                even++;
            } else {
                mod4++;
            }
        }
    }

    if(mod4 == 0) {
        if((even > 1) && (odd == 0)) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    } else {
        if(((even == 0) && (odd  == (mod4+1)))
            || (odd <= mod4)) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}
