#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<long long int> a(7);
    for(int i=0; i<7; i++){
        cin >> a[i];
    }

    long long int ans = (a[0] / 2 + a[3] / 2 + a[4] / 2) * 2;// I-type, J-type, L-type
    if(a[0] > 0 && a[3] > 0 && a[4] > 0){
        ans = max(ans, 3 + ((a[0]-1) / 2 + (a[3]-1) / 2 + (a[4]-1) / 2) * 2);
    }
    ans += a[1];// O-type    
    cout << ans << endl;
    return 0;
}