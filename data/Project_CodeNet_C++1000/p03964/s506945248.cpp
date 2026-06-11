#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    ll t, a;
    cin >> t >> a;

    for(int i = 1; i < n; i++){
        ll T, A;
        cin >> T >> A;
        if((double)t / a <= (double)T / A){
            while(a % A != 0) a++;
            t = a / A * T;
        }else{
            while(t % T != 0) t++;
            a = t / T * A;
        }
    }
    cout << a + t << endl;
}