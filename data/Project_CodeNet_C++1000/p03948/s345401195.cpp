#include <iostream>
using namespace std;

int main(void){
    int n, t, a[100010];
    cin >> n >> t;
    for (int i = 0; i < n; i++) cin >> a[i];
    
    int pf = 0, tm = 0, mn = 1e9;
    for (int i = 0; i < n; i++) {
        mn = min(mn, a[i]);
        if (a[i] - mn > pf) {
            pf = a[i] - mn;  tm = 1;
        }
        else if (a[i] - mn == pf) tm++;
    }
    
    cout << tm << endl;
    
}
