#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    long a, b;
    cin >> a >> b;

    long negativeCount=0;
    for (long i=a; i<b+1; ++i) {
        if (i==0) {
            cout << "Zero" << endl;
            return 0;
        } else if (i<0) {
            ++negativeCount;
        }
    }

    if (negativeCount%2 == 1) {
        cout << "Negative" << endl;
        return 0;
    } else {
        cout << "Positive" << endl;
        return 0;
    }

    return 0;
}