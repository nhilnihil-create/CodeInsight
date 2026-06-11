#include <bits/stdc++.h>
using namespace std;
int main(void){
    int k,s;
    int ans = 0;
    cin >> k >> s;
    for(int i=0;i<=k;i++) {
        for(int j=0;j<=k;j++) {
            int z=s-i-j;
            if(0<=z && z<=k) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
