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
    int n = s.size();
    int m;
    if(s[0] == s[n-1]){
        int cnt = 0;
        rep(i, n)if(s[i] == s[0])cnt++;
        m = cnt * 2 - 1;
    }else{
        int cnt1 = 0;
        int cnt2 = 0;
        rep(i, n){
            if(s[i] == s[0])cnt1++;
            else if(s[i] == s[n-1])cnt2++;
        }
        m =  2 * min(cnt1, cnt2);
    }
    if((n - m) % 2 == 0)cout << "Second" << endl;
    else cout << "First" << endl;
}