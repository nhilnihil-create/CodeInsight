#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int n, k;
    cin >> n >> k;
    
    int x[n];
    for (int i=0; i<n; i++) {
        cin >> x[i];
    }
    
    int ans = 0;
    
    for (int i=0; i<n; i++) {
        ans += min(x[i], abs(x[i]-k)) * 2;
    }
    
    cout << ans << endl;
}
