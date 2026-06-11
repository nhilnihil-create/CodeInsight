#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<map>
#include<functional>
#include<queue>
#include<stack>
#include<string.h>
#include<list>
#include<limits>
#include<bitset>
#include<ctype.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
const ll MOD=1000000007;
const ll INF=1000000000;
int main() {   
    int n,k;
    cin>>n>>k;
    ll a[5001];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    ll s;
    int ans=n;
    int ng=0;
    int ok=n+1;
    while(ok-ng>1){
        int mid=(ok+ng)/2;
        s=a[mid];
        a[mid]=0;
        bool dp[5001][5001]={false};
        dp[0][0]=true;
        bool f=false;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=k;j++){
                dp[i][j]|=dp[i-1][j];
                if(j>=a[i]){
                    dp[i][j]|=dp[i-1][j-a[i]];
                }
                if(i==n&&j>=k-s&&j<k&&dp[i][j]){
                    f=true;
                }
            }
        }
        if(f){
            ok=mid;
        }else{
            ng=mid;
        }
        a[mid]=s;
    }
    cout<<ng<<endl;
    getchar();
    getchar();
}

                           
