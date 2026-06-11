#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    string ans;
    for(int i = 0; i < 3; i++) {
        string s;
        cin >> s;
        ans.push_back(s[0] + 'A' - 'a');
    }
    cout << ans << endl;
    return 0;
}