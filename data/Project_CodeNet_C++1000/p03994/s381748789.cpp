#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
//const int INF = 2e9;
//const ll INF = 9e18;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int K;
    cin >> K;
    for (int i=0;i<s.size();i++){
        int p = s[i] - 'a';
        if (i==s.size()-1){
            s[i] = (char)(((p+K)%26) + 'a');
        } else if (p != 0 && 26 - p <= K) {
            K -= 26 - p;
            s[i] = 'a';
        }
    }
    cout << s << "\n";
}