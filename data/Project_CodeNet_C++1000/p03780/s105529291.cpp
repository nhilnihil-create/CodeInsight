#include<bits/stdc++.h>
using namespace std;

int a[5004] = {0};
bool dp[5004][5004];
int n, k;

bool check(int i){
    for(int j=0;j<n;++j){
        dp[j][0] = true;
        for(int l=1;l<=k;++l){
            dp[j][l] = false;
        }
    }

    for(int j=0;j<n;++j){
        if(j != i)dp[j][min(k,a[j])] = true;
        if(j > 0){
            for(int l=1;l<=k;++l){
                dp[j][l] = (dp[j][l] || dp[j-1][l]);
                if(j != i && l >= a[j])
                    dp[j][l] = (dp[j][l] || dp[j-1][l-a[j]]);
            }
        }
    }

    for(int j=max(0,k-a[i]);j<k;++j)
        if(dp[n-1][j])return true;
    return false;
}

int main(){
    cin >> n >> k;
    for(int i=0;i<n;++i){
        cin >> a[i];
    }
    sort(a, a+n);

    int unnecessary = -1, necessary = n;
    while(necessary - unnecessary > 1){
        int mid = (necessary + unnecessary) / 2;
        if(check(mid))necessary = mid;
        else unnecessary = mid;
    }

    cout << unnecessary + 1 << endl;

    return 0;
}
