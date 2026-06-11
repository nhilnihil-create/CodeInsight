#include <bits/stdc++.h>
using namespace std;

bool dp[5001][5001];

int n,k;
int a[5001];

int ans;
int t;

int main(){

    cin >> n >> k;

    ans = n;
    t = 0;

    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    sort(a,a+n);

    for(int i=n-1; i!=-1; i--){
        if(t+a[i] < k){
            t += a[i];
        }
        else{
            ans = min(ans,i);
        }
    }
    cout << ans << endl;

}