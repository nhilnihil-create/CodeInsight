#include <bits/stdc++.h>
using namespace std;

int64_t gcd(int64_t a, int64_t b){
    if (b == 0){
        return a;
    }
    return gcd(b, a%b);
}

int64_t lcm(int64_t a, int64_t b){
    return a/gcd(a, b)*b;
}


int main(){
    int n;
    cin >> n;

    int64_t ans = 1;
    for (int i = 0; i<n; i++){
        int64_t x;
        cin >> x;
        ans = lcm(x, ans);
    }

    cout << ans << endl;
}