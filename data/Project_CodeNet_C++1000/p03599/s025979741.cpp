#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}


int main() {
    int A,B,C,D,E,F;
    cin >> A >> B >> C >> D >> E >> F;
    vector<int>waters;
    rep(a,31) rep(b,31) {
        int sum = 100*A*a+100*B*b;
        if(sum<=F) waters.push_back(sum);
    }
    vector<int>sugars;
    rep(c,3001) rep(d,3001) {
        int sum = C*c+D*d;
        if(sum<=F) sugars.push_back(sum);
    }
    double noudo = -1;
    int ans1,ans2;
    for(auto water : waters) {
        for(auto sugar : sugars) {
            if(water + sugar > F) continue;
            int lim = (E*water)/100;
            
            if(sugar > lim) continue;
            if(water == 0) continue;
            double tmp = ((double)(sugar*100))/(double)(water+sugar);
            if(tmp > noudo) {
                noudo = tmp;
                ans1 = water + sugar;
                ans2 = sugar;
            }
        }
    }
    cout << ans1 << " " << ans2 << endl;

}