#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long a, b;
    cin >> a >> b;
    if(a*b <= 0) {
        cout << "Zero\n";
    } else {
        if((a > 0 && b > 0)) cout << "Positive\n";
        else {
            if((a-b+1)%2) cout << "Negative\n";
            else cout << "Positive\n";
        }
    }
    return 0;
}
