#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    set<int> s;
    rep(i,n){
        int a;
        cin >> a;
        if(s.count(a)==0) s.insert(a);
        else s.erase(a);   
    }
    int ans = s.size();
    cout << ans << endl;
    return 0;
}