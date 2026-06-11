#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int n, c, k;
    cin >> n >> c >> k;

    vector<long long int> t(n);
    for(int i=0; i<n; i++){
        cin >> t[i];
    }
    sort(t.begin(),t.end());

    long long int ans = 0, time = t[0], num = 1;
    for(int i=1; i<n; i++){
        if(num == c || t[i] - time > k){
            ans += 1;
            num = 1;
            time = t[i];
        }
        else num += 1;
    }
    ans += 1;
    cout << ans << endl;
    return 0;
}