#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
const int INF=1e9;

int main(){
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int ok=-1,ng=n;
    while(ng-ok>1){
        int mid=(ok+ng)/2;
        swap(a[mid],a[n-1]);
        bool dp[k]={};
        dp[0]=true;
        for(int i=0;i<n-1;i++){
            for(int j=k-1;j>=0;j--){
                if(dp[j]&&j+a[i]<k){
                    dp[j+a[i]]=true;
                }
            }
        }
        bool flag=false;
        for(int i=0;i<k;i++){
            if(dp[i]&&k-a[n-1]<=i){
                flag=true;
                break;
            }
        }
        (flag?ng:ok)=mid;
        swap(a[mid],a[n-1]);
    }
    cout<<ok+1<<endl;
}
