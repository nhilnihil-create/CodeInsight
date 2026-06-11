#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define per(i,n) for (int i = (n)-1; i >=0; --i)
using namespace std;
using ll = long long;
using vi = vector<int>;
using vv = vector<vi>;

int main(){
    int k,s;
    cin>>k>>s;
    int ans = 0;
    for(int x=0; x<=min(s,k); x++){
        for(int y=0; y<=min(s-x,k); y++){
            if(s-x-y<=k)ans++;
        }
    }
    
    cout << ans << endl;
    return 0;
}