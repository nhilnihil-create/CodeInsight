#include<bits/stdc++.h>
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const int MAX = 100000;
static const int NIL = -1;
using namespace std;


int main() {

    string s[3]; cin >> s[0] >> s[1] >> s[2];
    queue<char> q[3];
    char turn = 'a';
    rep(i,s[0].size()) q[0].push(s[0][i]);
    rep(i,s[1].size()) q[1].push(s[1][i]);
    rep(i,s[2].size()) q[2].push(s[2][i]);

    while(1){
        if(turn == 'a' && q[0].empty()) {
            cout << 'A';
            return 0;
        }else if(turn == 'b' && q[1].empty()){
            cout << 'B';
            return 0;
        }else if(turn == 'c' && q[2].empty()){
            cout << 'C';
            return 0;
        }
        if(turn == 'a'){
            turn = q[0].front();
            q[0].pop();
        }else if(turn == 'b'){
            turn = q[1].front();
            q[1].pop();
        }else {
            turn = q[2].front();
            q[2].pop();
        }
    }

    return 0;
}
