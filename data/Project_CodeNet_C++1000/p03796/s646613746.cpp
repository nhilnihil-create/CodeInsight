#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    int count = N;
    ll ans = 1;
    for (int i = 1; i <= count; i++)
    {
        ans *= i ;
        if(ans >= 1000000007){
            ans %= 1000000007;
        }
    }
    cout << ans << endl;
    

}
