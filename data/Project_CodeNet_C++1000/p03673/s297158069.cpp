#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(v) v.begin(), v.end()

int main(){
    int n;
    cin >> n;
    vector <long> a(n);
    rep(i,n) cin >> a[i];

    vector<long> ans(0);

    if(n%2==0){//n even
        for(int i=n-1; i>=1; i-=2){
            ans.push_back(a[i]);
        }
        for(int i=0; i<=n-2; i+=2){
            ans.push_back(a[i]);
        }

        
    }

    else{//n odd
        for(int i=n-1; i>=0; i-=2){
            ans.push_back(a[i]);
        }
        for(int i=1; i<=n-2; i+=2){
            ans.push_back(a[i]);
        }
    }


    for(int i=0; i<n; i++){
        if(i==n-1) cout << ans[i] << endl;
        else cout << ans[i] << " ";
    }

}