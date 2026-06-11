#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<ll, ll>;
const ll INF = 1e16;

void solver(string &s, vector<char> &ans){

    for(auto iter = s.begin(); iter != s.end(); ++iter){
        if(*iter != 'B') ans.push_back(*iter);
        else if(ans.size() != (size_t)0) ans.pop_back();
    }

    return;
}

int main(){

    string s;
    cin >> s;

    vector<char> ans;
    solver(s, ans);

    for(auto iter = ans.begin(); iter != ans.end(); ++iter) cout << *iter;

    return 0;
}