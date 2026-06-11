#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int lli;

int main(){
    lli n,a,b;
    cin >> n >> a >> b;
    vector<lli> x(n);
    for(int i=0; i<n; i++){
        cin >> x[i];    
    }
    lli ans = 0;
    for(int i=0; i<n-1; i++){
        ans += min(a*(x[i+1]-x[i]), b);
    }
    cout << ans << endl;
    return 0;
}