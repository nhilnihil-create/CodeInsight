#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<utility>
#include<algorithm>
#include<cstdio>
#include<iomanip>
#include<queue>
#include<stack>

#define ll int64_t
#define Rep(i, n) for (ll i = 0; i < n; i++)

using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll H, W;
    cin >> H >> W;
    vector<vector<string>> S(H, vector<string>(W));
    Rep (i, H) Rep (j, W) {
        cin >> S[i][j];
        if (S[i][j] == "snuke") cout << char(j+'A') << i+1 <<"\n";
    }

}