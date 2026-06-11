#include <iostream>
using namespace std;
int main(void){
    int n, ans = 0, t, a, low, benefit[100000], bmax = 0;
    cin >> n >> t;
    for(int i=0;i<n;i++){
        cin >> a;
        if(i>0)low = min(low, a);
        else low = a;
        benefit[i] = a - low;
        bmax = max(bmax, benefit[i]);
    }
    for(int i=0;i<n;i++){
        if(benefit[i] == bmax)ans++;
    }
    cout << ans << endl;
}
