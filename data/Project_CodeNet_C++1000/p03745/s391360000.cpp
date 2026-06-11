#include<bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 0;i < (int)(n);i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
int main(){
    int n;
    cin >> n;
    vector<ll>a(n);
    rep(i,n)cin >> a[i];
    int ans = 0;
    int now = 0;
    rep(i,n){
        if(i == 0)continue;
        if(now == 0 && a[i]>a[i-1])now = 1;
        else if(now == 0 && a[i] < a[i-1])now = -1;
        
        if(a[i]>a[i-1] && now == -1){
            ans++;
            now = 0;
        }else if(a[i]<a[i-1] && now == 1){
            ans++;
            now = 0;
        }
        
    }
    cout << ans+1 << endl;
    return 0;
}