#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
long long GCD(long long a, long long b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}
ll lcm(ll x, ll y) {
    return x / GCD(x, y) * y;//先に割り算をして掛けられる数を小さくして掛け算を行う
}
int main() {
    string S;
    cin >> S;
    bool hantei = false;
    int n = 0;
    for (int i = S.size() - 1; i >= 0; i--)
    {
        if(i % 2 != 0) { S.erase(i); continue; }
        S.erase(i);
        if (S.substr(0, S.size() / 2) == S.substr(S.size() / 2, S.size() / 2))
        {
            n = S.size();
            break;
        }
            
        
    }
    

    cout << n << endl;
    
    return 0;

}