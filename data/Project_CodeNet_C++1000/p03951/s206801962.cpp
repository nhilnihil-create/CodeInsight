#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back

typedef long long ll;
typedef pair<int, int> pi;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    string s, t;
    cin >> n;
    cin >> s;
    cin >> t;
    int len = s.length() + t.length();
    for(int i = 1;i <= min(s.length(), t.length());i++){
        if(s.substr(s.length() - i, i) == t.substr(0, i)){
            len = min(len, 2 * n - i);
        }
    }
    cout << len << endl;
    return 0;
}
