/*2020/03/15 ABC 050*/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using p = pair<int, int>;  


int main() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for(int i=0; i<n; i++) cin >> vec[i];
    sort(vec.begin(), vec.end());
    int j=-1, k=0;
    if(n%2==0) {
        for(int i=0; i<n; i++) {
            if(i%2==0) j+=2;
            if(vec[i]!=j) {
                cout << 0 << endl;
                return 0;
            }
        }
    } else {
        for(int i=0; i<n; i++) {
            if(i%2!=0) k+=2;
            if(vec[i]!=k) {
                cout << 0 << endl;
                return 0;
            }
        } 
    }
    int ans=1;
    for(long i=0; i<n/2; i++){
            ans *= 2;
            ans %= (1000000000+7);
        }
    cout << ans << endl;

    return 0;
}
