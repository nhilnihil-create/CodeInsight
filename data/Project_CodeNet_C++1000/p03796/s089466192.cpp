#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long ans = 1;
    for (int i=1; i<=n; i++){
        ans = (ans * i) % (1000000007);
    }
    cout << (ans) << "\n";

    return 0;
}
