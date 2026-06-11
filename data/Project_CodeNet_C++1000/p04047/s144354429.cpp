#include <bits/stdc++.h>

using namespace std;

#define ll long long;
#define fo(i,n) for(int i=0;i<n;i++)

int n,ans;

void solve() {
    int n,ans = 0; cin >>n;
    int arr[2*n];
    fo(i,2*n){
        cin >> arr[i];
    }
    sort(arr,arr+2*n);
    for(int i =0; i < 2*n; i +=2){
        ans +=arr[i];
    }
    cout <<ans;
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    solve();
    
    
    return 0;
}
