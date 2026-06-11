#include<bits/stdc++.h>
const int N = 1e5 + 5;
using namespace std;

int n, a[N];
bool t;

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    while (true){
        bool sum = 0;
        for (int i = 1; i <= n; i++) sum ^= ((a[i]-1)&1);
        if (sum){
            if (!t) cout << "First";
            else cout << "Second";
            return 0;
        }
        int cnt = 0, cnt1 = 0, gcd = 0;
        for (int i = 1; i <= n; i++) cnt += a[i]&1, cnt1 += a[i] == 1;
        if (cnt == 1 && !cnt1){
            for (int i = 1; i <= n; i++){
                if (a[i]&1) a[i]--;
                gcd = __gcd(gcd, a[i]);
            }
            for (int i = 1; i <= n; i++) a[i] /= gcd;
        }
        else{
            t ^= 1;
            if (!t) cout << "First";
            else cout << "Second";
            return 0;
        }
        t ^= 1;
    }
}
