#include <bits/stdc++.h>
using namespace std;
#define fo(i,n) for(int i=0;i<n;i++)
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
int main(){
    int n;cin >>n;
    long long arr[3*n];
    fo(i,3*n){
        cin >> arr[i];
    }
    sort(arr,arr+(3*n));
    long long ans = 0;
    for(int j = 1;j<=n;++j){
        ans += arr[(3*n)-(2*j)];
    }
    cout << ans;
}