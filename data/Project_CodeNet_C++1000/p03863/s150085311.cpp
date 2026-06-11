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
    if(s[0] == s[n - 1]) n--;
    if(n % 2 == 0) cout << "Second" << endl;
    else cout << "First" << endl;
    return 0;
}