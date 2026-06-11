#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    string s; cin >> s;
    int ss = s.size();
    for (int i = 0; i < ss-1; i++){
        if(i != ss-2){
            char x = s[i];
            if(x == s[i+1]){
                cout << i+1 << " " << i+2 << endl;
                return 0;
            } else if(x == s[i+2]){
                cout << i+1 << " " << i+3 << endl;
                return 0;
            }
        } else {
            char x = s[i];
            if(x == s[i+1]){
                cout << i+1 << " " << i+2 << endl;
                return 0;
            }
        }
    }

    cout << -1 << " " << -1 << endl;
    return 0;
}