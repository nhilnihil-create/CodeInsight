#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for (int i = 0; i < (n); ++i)

int main() {
    int H,W,N,x=1;
    cin >> H >> W >> N;
    vector<int> a(N);
    vector<vector<int>> r(H, vector<int>(W));
    rep(i,N)
        cin >> a.at(i);
    
    rep(i,H)
        rep(j,W) {
            if(i%2 == 0)
                r.at(i).at(j) = x;
            else
                r.at(i).at(W-1-j) = x;
            a.at(x-1)--;
            if(a.at(x-1) == 0)
                x++;
        }

    rep(i,H) {
        rep(j,W)
            cout << r.at(i).at(j) << " ";
        cout << endl;
    }
}