#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define all(x) x.begin(),x.end()
typedef long long ll;
ll mod = 1000000007;
ll inf = 1e18;
int main(){

    int n,k;
    cin >> n >> k;
    vector<int> d(k);
    rep(i,k) cin >> d[i];

    while(1){
        int num=n;
        bool ans=true;
        while(num>0){
            rep(i,k) if(num%10==d[i]) ans=false;
            num/=10;
        }
        // cout << n << endl;
        if(ans) break;
        n++;
    }

    cout << n << endl;
    
    return 0;
}