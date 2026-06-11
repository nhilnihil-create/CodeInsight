#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k,x,y;
    cin >> n >> k >> x >> y;
    int ans = 0;
    for(int day = 0; day < n; day++){
        if(day < k) ans += x;
        else ans += y;
    }
    cout << ans << endl;
}