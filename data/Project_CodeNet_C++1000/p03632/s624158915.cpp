#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int A,B,C,D;
    cin >> A >> B >> C >> D;
    int ans = 0;
    for (int i = A; i <= B; i++) {
        if (C <= i && i <= D) {
            ans++;
        }
    }
    if (ans != 0) {
        cout << ans-1 << endl;
        return 0;
    }
    cout << ans << endl;
}