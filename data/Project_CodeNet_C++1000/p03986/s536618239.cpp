#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    string s;
    cin >> s;
    int l = 0;
    int r = 0;
    rep(i, s.size()){
        if(s[i] == 'T'){
            if(r > 0)r--;
            else l++;
        }else{
            r++;
        }
    }
    cout << l + r << endl;
}