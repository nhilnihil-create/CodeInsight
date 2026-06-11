#include <bits/stdc++.h>
using namespace std;
#define REP(i, init, n) for(int i = (int)(init); i < (int)(n); i++)

#define vi vector<int>
#define vl vector<long>
#define vvi vector<vector<int>>
#define vvl vector<vector<long>>
#define pint pair<int, int>
#define plong pair<long, long>

int main() {
    int N;
    string s, ans;
    cin>>N>>s;
    vector<string> init={"SS", "SW", "WS", "WW"};
    for(string i: init){
        string ans = i;
        REP(j, 1, N){
            if(s[j] == 'o'){
                if(ans[j] == 'S') ans += (ans[j-1] == 'S') ? "S" : "W";
                if(ans[j] == 'W') ans += (ans[j-1] == 'S') ? "W" : "S";   
            }else{
                if(ans[j] == 'S') ans += (ans[j-1] == 'S') ? "W" : "S";
                if(ans[j] == 'W') ans += (ans[j-1] == 'S') ? "S" : "W";   
            }
        }
        bool correct = false;
        if(s[0] == 'o'){
            if(ans[0] == 'S' && (ans[N-1] == ans[1])) correct = true;
            if(ans[0] == 'W' && (ans[N-1] != ans[1])) correct = true;
        }else{
            if(ans[0] == 'S' && (ans[N-1] != ans[1])) correct = true;
            if(ans[0] == 'W' && (ans[N-1] == ans[1])) correct = true;
        }
        if(ans[N] == ans[0] && correct){
            ans.pop_back();
            cout << ans << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}