#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    ll n, m;
    cin >> n >> m;
    if(n >= m / 2){
        cout << m / 2 << endl;
    }else{
        cout << n + (m - n * 2) / 4 << endl;
    }
    
}