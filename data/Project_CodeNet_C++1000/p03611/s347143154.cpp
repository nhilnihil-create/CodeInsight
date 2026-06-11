#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long ;
using P = pair<int, int>;

void solver(int N, vector<int> &a, int &ans){

    map<int, int> dict;

    for(auto iter = a.begin(); iter != a.end(); ++iter){
        auto buf = iter;
        ++dict[*buf+1];
        ++dict[*buf];
        ++dict[*buf-1];
    }

    for(auto p: dict){
        auto num = p.second;
        ans = max(num, ans);
    }

    return;
}

int main(){

    int N;
    cin >> N;
    vector<int> a(N);
    for(auto iter = a.begin(); iter != a.end(); ++iter) cin >> *iter;

    int ans{};
    solver(N, a, ans);
    cout << ans << endl;

    return 0;
}