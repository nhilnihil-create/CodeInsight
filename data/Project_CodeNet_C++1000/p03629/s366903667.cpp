#include <string>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    string s; cin >> s;
    int N = s.length();

    vector<int> mi(N+1), bit(N+1);
    for(int i=N-1; i>=0; i--) {
        bit[i] = bit[i+1] | (1 << (s[i] - 'a'));
        while(bit[i] >> mi[i] & 1) mi[i]++;
        if(mi[i] == 26) mi[i] = 0,  bit[i] = 0;
    }
    string ans = "";
    for(int i=0; i<N; i++) {
        char c = 'a' + mi[i];
        ans += c;
        while(i < N && s[i] != c) i++;
    }
    cout << ans << endl;
    return 0;
}