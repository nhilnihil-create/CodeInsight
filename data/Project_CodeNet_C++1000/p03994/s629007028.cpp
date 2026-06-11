#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int k;
    cin >> s >> k;
    for(int i = 0; i < s.size(); ++i) {
        int dist_a = 'z' - s[i] + 1;
        if(s[i] == 'a') continue;
        if(dist_a <= k) {
            s[i] = 'a';
            k -= dist_a;
        }
    }
    if(k > 0) s[s.size()-1] = (s[s.size()-1] + k%26)%'a' + 'a'; 
    cout << s << '\n';
}
