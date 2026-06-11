#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> x(n);
    long long ans = 0;
    for(int i = 0; i < n; i++){
        cin >> x[i];
        ans += min(x[i], abs(x[i] - k)) * 2;
    }
    cout << ans << endl;
}