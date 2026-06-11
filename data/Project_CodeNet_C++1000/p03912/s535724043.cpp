#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using ll = long long;
using VI = vector<int>;
using VVI = vector<vector<int>>;
using P = pair<int, int>;

int main(){
    int n,m;
    cin >> n >> m;
    VI x(n);
    rep(i,n) cin >> x[i];

    sort(x.begin(), x.end());

    VVI y(m,VI());
    rep(i,n){
        int r = x[i] % m;
        y[r].push_back(x[i]);
    }

    int ans=0;
    ans += y[0].size() / 2;
    if(m%2 == 0) ans += y[m/2].size() / 2;

    rep2(i,1,(m+1)/2){
        VI s = y[i];
        VI t = y[m-i];
        if(s.size() < t.size()) swap(s,t);
        sort(s.begin(), s.end());
        bool flag = true;

        while(s.size() > t.size()+1 && flag){
            flag = false;
            rep(i,s.size()-1){
                if(s[i] == s[i+1]){
                    s.erase(s.begin()+i);
                    s.erase(s.begin()+i);
                    flag = true;
                    ans++;
                    break;
                }
            }
        }
        ans += t.size();
    }

    cout << ans << endl;

    return 0;
}
