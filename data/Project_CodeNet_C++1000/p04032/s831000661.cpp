#include <bits/stdc++.h>
using namespace std;
#define REP(i,a) for(int i = 0; i < (a); i++)
#define ALL(a) (a).begin(),(a).end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const long long LINF = 1e18;
const long long MOD = 1e9 + 7;

signed main(){
    string s;
    cin >> s;
    int n = s.size();
    char pre = s[0];
    for(int i = 1; i < n; i++){
        if(s[i] == pre){
            cout << i << " " << i + 1 << endl;
            return 0;
        }
        pre = s[i];
    }
    pre = s[0];
    for(int i = 2; i < n; i += 2){
        if(s[i] == pre){
            cout << i - 1 << " " << i + 1 << endl;
            return 0;
        }
        pre = s[i];
    }
    pre = s[1];
    for(int i = 3; i < n; i += 2){
        if(s[i] == pre){
            cout << i - 1 << " " << i + 1 << endl;
            return 0;
        }
        pre = s[i];
    }
    cout << -1 << " " << -1 << endl;
    return 0;
}