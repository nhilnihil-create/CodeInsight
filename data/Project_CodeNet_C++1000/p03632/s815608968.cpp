#include <bits/stdc++.h>
using namespace std;

int main() {

    int a,b,c,d;
    cin >> a >> b >> c >> d;
    int ans = 0;
    for (int i = 0; i <= 100; i++) {
        if(a <= i && i <= b-1 && c <= i && i <= d-1){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}