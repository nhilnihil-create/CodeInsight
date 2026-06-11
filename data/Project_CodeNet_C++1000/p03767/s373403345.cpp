#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i=0; i<(int)(n); i++)

int main() {
    int N;
    cin >> N;
    vector<long long int> powers(N*3);
    rep(i, powers.size()){
        cin >> powers.at(i);
    }
    sort(powers.begin(), powers.end(), greater<long long int>());
    vector<vector<long long int>> teams(N, vector<long long int>(3));
    int c = 0;
    int d = 0;
    rep(i, powers.size()){
        if(i < N*2){
            teams.at(c).at(0) = powers.at(i);
            i++;
            teams.at(c).at(1) = powers.at(i);
            c++;
        } else {
            teams.at(d).at(2) = powers.at(i);
            d++;
        }
    }
    long long int ans = 0;
    rep(i, teams.size()){
        ans += teams.at(i).at(1);
        // rep(j, 3){
        //     cout << teams.at(i).at(j);
        // }
        // cout << endl;
    }

    cout << ans << endl;
}