#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();
    int ans = 1<<30;;
    for(char c='a';c<='z';++c) {
        int prev = -1, tmpans = 0;
        for(int i=0;i<n;++i) {
            if(s[i] == c) {
                tmpans = max(tmpans, i-1-prev);
                prev = i;
            }
        }
        tmpans = max(tmpans, n-1-prev);
        ans = min(ans, tmpans);
    }
    cout << ans << endl;
}