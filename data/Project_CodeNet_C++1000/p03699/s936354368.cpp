#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    vector<int> x;
    int ans = 0;
    rep(i,n) {
        int s;
        cin >> s;
        if(s%10!=0) x.push_back(s); 
        ans+=s;
    }
    sort(all(x));
    if(x.size()==0 && ans%10==0){cout << 0 << endl; return 0;}
    if(ans%10==0) ans-= x[0];
    cout << ans << endl;

    return 0;
}