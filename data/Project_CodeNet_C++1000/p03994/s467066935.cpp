#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0 ,-1};
signed main() {
    string s;
    int K;
    cin >> s >> K;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == 'a') {
            continue;
        }
        else if('z'-s[i]+1 <= K) {
            K-='z'-s[i]+1;
            s[i] = 'a';
        }
    }
    for(int i = 0; i < K; i++) {
        if(s[s.size()-1] == 'z') {
            s[s.size()-1] = 'a';
        }
        else {
            s[s.size()-1] = (s[s.size()-1]-'a'+1)+'a';
        }
    }
    cout << s << endl;
}
