#include <bits/stdc++.h>
using namespace std;

int main(){

    string s;
    cin >> s;

    int num = s.size();
    int l = 1e6, r = 0, ans = -1;
    for (int i=0; i<num; i++){
        int buf;
        if (s.at(i) == 'A') {
            buf = i;
            l = min(buf, l);
        }
        if (s.at(num-1-i) == 'Z') {
            buf = num-1-i;
            r = max(buf, r);
        }
        buf = r-l+1;
        ans = max(buf, ans);
    }
    cout << ans << endl;
    return 0;
}