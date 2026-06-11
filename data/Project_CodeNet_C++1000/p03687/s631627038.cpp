#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
const ll INF = 1e16;

void solver(string s, int &ans){

    int ans_buf = 1e6;
    string old_s, new_s;

    for(char c = 'a'; c <= 'z'; ++c){
        old_s = s;

        for(int cnt = 0; ; ++cnt){
            if(old_s.empty()) break;

            else if(old_s == string(old_s.size(), c)){
                ans_buf = min(cnt, ans_buf);
                break;
            }

            new_s = "";
            for(int i = 0; i != (int)(old_s.size())-1; ++i){
                if(old_s.at(i) == c || old_s.at(i+1) == c) new_s += c;
                else new_s += old_s.at(i);
            }
            old_s = new_s;
        }
    }
    ans = ans_buf;

    return;
}

int main(){

    string s;
    cin >> s;

    int ans;
    solver(s, ans);

    cout << ans << endl;
    cerr << string(s.size(), 'a');
    return 0;
}
