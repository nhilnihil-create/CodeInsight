#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using ll = long long;
const ll MOD = 1e9+7;
const int INF = 1001001001;
// const ll INF = 1000000000000000000LL;
  
int main() {
    int cnt = 0;
    int cnt_s = 0;
    string x;
    cin >> x;
    int n = x.size();
    rep(i,n){
        if(x[i]=='S'&&x[i+1]=='T') {
            i++;
            continue;
        }
        if(x[i]=='S') cnt_s++;
        if(x[i]=='T') {
            if(cnt_s>0) cnt_s--;
            else cnt++;
        }
        
    }
    cout << cnt*2 << endl;
    return 0;
}