#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <queue>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()

int main() {
    int n;
    cin>>n;
    vector<int>a(n);
    rep(i,n)cin>>a[i];
    sort(all(a),greater<int>());
    int b=1;
    rep(i,n){
        if(a[i]!=n-1-(i/2)*2)b=0;
    }
    if(b==0)cout<<0;
    else{
        int ans=1;
        int p=n/2;
        rep(i,p){
            ans*=2;
            ans%=1000000007;
        }
        cout<<ans;
    }
	return 0;
}
