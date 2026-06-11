#include<bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 0;i < (int)(n);i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
int main(){
    int n;
    cin >> n;
    vector<int>a(n);
    rep(i,n)cin >> a[i];
    vector<int>data(100001,0);
    rep(i,n)data[a[i]]++;
    int ans = 0;
    rep(i,data.size()-3){
        int x = data[i]+data[i+1]+data[i+2];
        ans = max(ans,x);
    }
    cout << ans << endl;
    return 0;
}