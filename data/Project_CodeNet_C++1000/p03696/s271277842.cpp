#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
typedef long long ll;
const int INT_INF = 1e9;
const ll INF = 1LL << 30;
const ll MOD = 1e9 + 7;


int main() {
    int n; cin >> n;
    string s; cin >> s;

    int cnt = 0, x = 0, y = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '(') cnt++;
        else{
            if(cnt == 0) x++;
            else cnt--;
        }
    }
    cnt = 0;
    for(int i = n - 1; i >= 0; i--){
        if(s[i] == ')') cnt++;
        else{
            if(cnt == 0) y++;
            else cnt--;
        }
    }

    for(int i = 0; i < x; i++) cout << '(';
    cout << s;
    for(int i = 0; i < y; i++) cout << ')';
    cout << "\n";

}
