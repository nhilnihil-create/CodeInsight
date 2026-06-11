#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
#define ll long long

    int main (){
    int n,k;
    cin >> n >> k;
    int ans = 0;
    rep(i,n){
        int x;
        cin >> x;
        if(abs(k-x)>x){
            ans+=x*2;
        }
        else{
            ans+=abs(k-x)*2;
        }
    }
        cout << ans << endl;
        return 0;

       
    }