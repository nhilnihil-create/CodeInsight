#include<bits/stdc++.h>
// sakib malik
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int t = 1;
    int ans = 0;
    int f = 0;
    while(ans < n){
        t = a[t];
        ans++;
        if(t == 2)break;
        //if(t == a[t]){f = 1; break;}
    }
    if(ans < n)cout << ans;
    else cout << -1;

}