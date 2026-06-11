#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    int a, b;
    cin >> a >> b;
    if(a <= 0 && 0 <= b)cout << "Zero" << endl;
    else{
        if(a < 0){
            int c;
            if(b < 0)c = b - a + 1;
            else c = abs(a);
            if(c % 2 == 0)cout << "Positive" << endl;
            else cout << "Negative" << endl;
        }else{
            cout << "Positive" << endl;
        }
    }
    
}