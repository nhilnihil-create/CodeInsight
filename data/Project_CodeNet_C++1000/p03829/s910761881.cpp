#include <iostream>
#include <vector>
using namespace std;

int main(){
    long long int n, a, b;
    cin >> n >> a >> b;
    vector<int> x(n);
    for(int i = 0; i < n; i++) cin >> x[i];
    long long int ans = 0;
    for(int i = 1; i < n; i++){
        if((x[i]-x[i-1])*a > b) ans += b;
        else ans += a*(x[i]-x[i-1]);
    }
    cout << ans << endl;
    return 0;
}