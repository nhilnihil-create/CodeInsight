#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main() {
    string s; cin >> s;
    int n = s.size() - 1;
    long ans = 0;

    for(int bit=0; bit<(1<<n); bit++){
        long tmp = 0;
        for(int i=0; i<n; i++){
            tmp += s[i] - '0';
            if(bit & (1 << i)){
                ans += tmp;
                tmp = 0;
            }
            tmp *= 10;
        }
        tmp += s[n] - '0';//tmp += s.back() - '0';
        ans += tmp;
    }
    cout << ans << endl;
}