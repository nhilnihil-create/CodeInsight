#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define sc(x) scanf("%d",&x);
int main(){
    string s;
    cin >> s;
    int len = s.size();
    typedef pair<int, int> P;
    P ans = make_pair(-1, -1);
    if (len == 2){
        if(s[0] == s[1]) ans = make_pair(0, 1);
    }
    else if (s[0] == s[1] || s[0] == s[1] || s[1] == s[2]){
        ans = make_pair(0, 2);
    }
    else {
        for (int i = 3; i < len; i++){
            if (s[i] == s[i - 1] || s[i] == s[i - 2]){
                ans = make_pair(i - 2, i);
            }
        }
    }
    if (ans.first == -1) cout << -1 << " " << -1 << endl;
    else cout << ans.first + 1 << " " << ans.second + 1 << endl;
    return 0;
}