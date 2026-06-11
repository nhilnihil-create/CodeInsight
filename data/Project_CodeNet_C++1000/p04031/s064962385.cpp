#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    long long ans=1e9;
    for(int i=-100; i<=100; i++){
        long long tmp=0;
        for(int j=0; j<n; j++){
            tmp += pow(a[j]-i,2);
        }
        ans = min(ans,tmp);
    }
    cout << ans << endl;
    return 0;
}