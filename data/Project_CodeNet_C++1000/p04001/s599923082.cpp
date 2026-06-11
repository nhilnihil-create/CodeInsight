#include<bits/stdc++.h>
using namespace std;
#define int long long int
// #include"../Template.cpp"

string s;
int n;

vector<int> solve(int i) {
    if(i == (n-1)) {
        vector<int> vec = {s[i]-'0'};
        return vec;
    }
    vector<int> vec;
    int no = s[i] - '0';
    for(int curr = i+1; curr < n; curr ++) {
        
        vector<int> res = solve(curr);
        for(auto j : res) {
            vec.push_back({j + no});
        }
        no = (no * 10) + (s[curr]-'0');
    }
    vec.push_back(no);
    return vec;
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> s;
    n = s.size();
    vector<int> sum = solve(0);
    int ans = accumulate(sum.begin(), sum.end(), 0LL);
    cout << ans << endl;
    return 0;
}