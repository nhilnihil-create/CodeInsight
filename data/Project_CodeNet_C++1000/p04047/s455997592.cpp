#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int A[2*n+5];
    for(int i = 0; i < 2*n; i++) cin >> A[i];
    sort(A,A+2*n);
    int ans = 0;
    for(int i = 2*n-1; i >= 0; i-= 2){
        ans += min(A[i],A[i-1]);
    }
    cout << ans << endl;
    return 0;
}
