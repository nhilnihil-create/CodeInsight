#include <bits/stdc++.h>
using namespace std;

//#define int long long
typedef long long ll;
//const int INF = 2e9;
//const ll INF = 9e18;


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int A,B,C,D,E,F;
    cin >> A >> B >> C >> D >> E >> F;
    vector<int> water;
    for (int i=0;100*i<=F;i++){
        for (int j=0;100*j<=F;j++){
            int x = 100*A*i + 100*B*j;
            if (x<=F) water.push_back(x);
        }
    }
    vector<int> sugar;
    for (int i=0;i<=F;i++){
        for (int j=0;j<=F;j++){
            int y = C*i + D*j;
            if (y <= F) sugar.push_back(y);
        }
    }
    
    double mx = 0.0;
    pair<int,int> ans = make_pair(100*A,0);
    for (int i=0;i<water.size();i++){
        for (int j=0;j<sugar.size();j++){
            int w = water[i];
            int s = sugar[j];
            if (w+s>F) continue;
            if (w/100*E >= s && 100.0F*s/(w+s) > mx) {
                mx = 100.0F*s/(w+s);
                ans = make_pair(w, s);
            }
        }
    }
    cout << ans.first + ans.second << " " << ans.second << "\n";
}