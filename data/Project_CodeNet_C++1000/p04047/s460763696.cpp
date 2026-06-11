#include <bits/stdc++.h>
using namespace std;
#define fo(i,n) for(int i=0;i<n;i++)
int main(){
    cin.tie(0); ios::sync_with_stdio(false);
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


