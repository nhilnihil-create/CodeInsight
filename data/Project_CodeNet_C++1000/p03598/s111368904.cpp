#include<bits/stdc++.h>
using namespace std;

int n, k;

int main(void){
    cin >> n >> k;
    vector<int> x(n);
    for(int i = 0; i < n; i++) cin >> x[i];
    int res = 0;
    for(int i = 0; i < n; i++){
        res+=min(abs(x[i]), abs(k-x[i]));
    }
    res*=2;
    cout << res << endl;
    return 0;
}
