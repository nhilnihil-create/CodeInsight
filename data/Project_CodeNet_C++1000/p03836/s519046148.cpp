#include <bits/stdc++.h>
using namespace std;

const int dx[4] = { 0, 1, 0, -1 };
const int dy[4] = { 1, 0, -1, 0 };
const char dc[4] = { 'U', 'R', 'D', 'L' };
vector<vector<bool>> chk;
vector<vector<pair<int, string>>> path;

int main(){
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;

    string s = "";
    for (auto i = sy; i < ty; i++) s.push_back('U');
    for (auto i = sx; i < tx; i++) s.push_back('R');
    for (auto i = sy; i < ty; i++) s.push_back('D');
    for (auto i = sx; i < tx; i++) s.push_back('L');

    s.push_back('L');
    for (auto i = sy; i <= ty; i++) s.push_back('U');
    for (auto i = sx; i <= tx; i++) s.push_back('R');
    s += "DR";
    for (auto i = sy; i <= ty; i++) s.push_back('D');
    for (auto i = sx; i <= tx; i++) s.push_back('L');
    s.push_back('U');

    cout << s << endl;
    return 0;
}