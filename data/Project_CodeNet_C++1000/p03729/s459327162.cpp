#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    string a, b, c;
    cin >> a >> b >> c;
    if(a[(int)a.size()-1]==b[0] && b[(int)b.size()-1]==c[0]){
        cout << "YES" << endl;
    }else cout << "NO" << endl;
    
}