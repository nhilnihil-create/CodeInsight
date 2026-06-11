#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();
// freopen("input.txt", "r", stdin);


int main() {
    string s;
    cin >> s;
    unordered_set<char> cand;
    auto sub = [&] (string ss, char c) -> int {
        int iter = 0;
        while(true) {
            int cnt = 0;
            for(int i = 0; i < ss.size(); i++) {
                if (ss[i] == c)
                    cnt += 1;
            }
            if(cnt == ss.size())
                return iter;
            iter++;
            for(int i = 1; i < ss.size(); i++) {
                if (ss[i] == c)
                    ss[i-1] = c;
            }
            ss.pop_back();
        }
    };
    for(char c: s)
        cand.insert(c);
    int ans = s.size();
    for(char c: cand) {
        ans = min(ans, sub(s, c));
    }
    cout << ans << endl;
    return 0;
}


