#include<bits/stdc++.h>
using namespace std;

int n,k;
int arr[5001];
int dp[5001];

void add(int x){
    for(int i=k-1;i>=x;i--){
        dp[i] = dp[i]+dp[i-x];
    }
}

void del(int x){
    for(int i=0;i<k-x;i++){
        dp[i+x] = dp[i+x] - dp[i];
    }
}

int main(){
    cin>>n>>k;

    for(int i=0;i<n;i++){
        cin>>arr[i];
        arr[i] = min(arr[i],k);
    }
    dp[0] = 1;
    for(int i=0;i<n;i++){
        add(arr[i]);
    }

    int ans = 0;
    for(int i=0;i<n;i++){
        del(arr[i]);
        int f = 0;
        for(int j=k-arr[i];j<k;j++){
            if(dp[j]){
                f = 1;
                break;
            }
        }
        if(!f) ans++;
        add(arr[i]);
    }
    cout<<ans;
}