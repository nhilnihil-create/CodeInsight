#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int N;
    cin >> N;
    int amax = 0;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        if (a >= amax) {
            ans = a+b;
            amax = a;
        }
    }
    cout << ans << endl;
    return 0;
}