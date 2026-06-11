#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    for(int i = n; i >= 0; i--){
        //cout << t.substr(0, i) << " " << s.substr(n-i) << endl;
        if(t.substr(0, i) == s.substr(n-i)){
            cout << n*2 - i << endl;
            return 0;
        }
    }
}
