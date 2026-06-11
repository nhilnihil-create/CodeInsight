#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

int main(){
    int k,t; cin >> k >> t;
    int a[t], ma = INT_MIN;
    for(int i = 0; i < t; i++){
        cin >> a[i];
        ma = max(ma, a[i]);
    }
    cout << max(ma -1 - (k-ma), 0) << endl;

    return 0;
}