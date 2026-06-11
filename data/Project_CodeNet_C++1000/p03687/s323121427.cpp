#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
int main(){
    string s;
    cin >> s;
    vector<int> G[26];
    for(int i = 0; i < s.size(); i++){
        G[s[i] - 'a'].push_back(i);
    }
    int ans = 1e9;
    for(int i = 0; i < 26; i++){
        vector<int> v = G[i];
        if(v.size() == 0) continue;
        int m = 0;
        int res = -1;
        for(int j: v){
            m = max(m, j - res - 1);
            res = j;
        }
        m = max(m, (int)s.size() - 1 - res);
        ans = min(ans, m);
    }
    cout << ans << endl;
}