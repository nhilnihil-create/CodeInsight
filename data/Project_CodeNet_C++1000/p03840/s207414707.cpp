#include <bits/stdc++.h>
using namespace std;
#define int long long
//0oooo0
//000000
signed main() {
    int I,O,T,J,L,S,Z;
    cin >> I >> O >> T >> J >> L >> S >> Z;
    int ans = (I/2*4+O*2+J/2*4+L/2*4)/2;
    int cnt = I%2+J%2+L%2;
    if(cnt == 3) {
        ans+=3;
    }
    if(cnt == 2) {
        if(I != 0 && J != 0 && L != 0){
            ans+=1;
        }
    }
    cout << ans << endl;
}