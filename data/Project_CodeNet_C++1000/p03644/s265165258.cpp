#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
#define ll long long

    int main (){
        int n;
        cin >> n;
        int ans=1;
        while(n>=ans*2){
            ans*=2;
        }
        cout << ans << endl;
        return 0;
    }