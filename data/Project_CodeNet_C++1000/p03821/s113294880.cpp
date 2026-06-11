#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long int a[n], b[n];
    for(int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }
    long long int push_sum = 0;
    for(int i = n-1; i >= 0; --i) {
        if((push_sum + a[i])%b[i] != 0) 
            push_sum += b[i] - (push_sum + a[i])%b[i];
    }

    cout << push_sum << '\n';

    return 0;
}
