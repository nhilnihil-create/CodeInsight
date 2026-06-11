#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
ll factorial(int i) {       //階乗
    if (i == 0) return 1;
    return (factorial(i - 1)) * i;
}
 
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> num(n, 1);
    vector<bool> red(n, 0);
    red[0] = 1;
    vector<vector<int>> d(m, vector<int> (2));
    rep(i, m) {
        cin >> d[i][0] >> d[i][1];
        d[i][0]--;
        d[i][1]--;
    }
    rep(i, m) {
        if(red[d[i][0]]) red[d[i][1]] = 1;
        num[d[i][0]]--;
        num[d[i][1]]++;
        if(num[d[i][0]] == 0) red[d[i][0]] = 0;
    }
    int count = 0;
    rep(i, n) if(red[i]) count++;
    cout << count << "\n";
}