#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int N = s.size();
    long long ans;
    for(int bit = 0; bit < (1 << N - 1); bit++){
        long long tmp = 0;
        for(int i = 0; i < N - 1; i++){
            tmp *= 10;
            tmp += s.at(i) - '0';
            if(bit & (1 << i)) ans += tmp, tmp = 0;
        }
        tmp *= 10;
        tmp += s.back() - '0';
        ans += tmp;
    }

    cout << ans << endl;
}