#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const long double PI = (acos(-1));
#define rep(i, x, n) for (int i = x; i < (int)(n); i++)
#define sc(x) scanf("%d",&x)
#define scll(x) scanf("%lld",&x)
int main(){
    int a = -1, b = -1;
    string s; cin >> s;
    rep(i, 0, s.size()-1){
        if (s[i] == s[i+1]){
            a = i + 1;
            b = i + 2;
            break;
        }else if (i+2 < s.size() && s[i] == s[i+2]){
            a = i + 1;
            b = i + 3;
            break;
        }
    }
    cout << a << " " << b << endl;
    return 0;
}