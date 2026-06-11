#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

int main(){
    string s, t;
    cin >> s >> t;

    int N = s.size();
    int M = t.size();

    int sa[N + 1] = {};
    int sb[N + 1] = {};
    int ta[M + 1] = {};
    int tb[M + 1] = {};

    for(int i = 0; i < N; i++){
        sa[i + 1] = sa[i];
        sb[i + 1] = sb[i];
        if(s[i] == 'A') sa[i + 1]++;
        if(s[i] == 'B') sb[i + 1]++;
    }

    for(int i = 0; i < M; i++){
        ta[i + 1] = ta[i];
        tb[i + 1] = tb[i];
        if(t[i] == 'A') ta[i + 1]++;
        if(t[i] == 'B') tb[i + 1]++;
    }

    int Q;
    cin >> Q;

    vector<string> ans;

    for(int i = 0; i < Q; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        int x = ((sa[b] - sa[a - 1]) % 3) - ((sb[b] - sb[a - 1]) % 3);
        int y = ((ta[d] - ta[c - 1]) % 3) - ((tb[d] - tb[c - 1]) % 3);
        x += 3;
        y += 3;
        x %= 3;
        y %= 3;

        if(x == y){
            ans.push_back("YES");
        } else {
            ans.push_back("NO");
        }
    }

    for(string s : ans){
        cout << s << endl;
    }

    return 0;
}
