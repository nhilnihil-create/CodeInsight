#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define int ll
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define pb push_back
#define all(a) (a).begin(),(a).end()
#define rev(a) (a).rbegin(),(a).rend()
#define pll pair<ll,ll>
#define rep(i,a,b) for(long long i = (a); i < (b); i++)
int dp[51][51][2501];
int c = 0;
int a, n;
int solve(int arr[], int index, int currCount, int sum){
        if(index == n)return 0;
        if(dp[index][currCount][sum] != -1)return dp[index][currCount][sum];
        int opt1 = solve(arr, index + 1, currCount + 1, sum + arr[index]);
        int opt2 = solve(arr, index + 1, currCount, sum);
        sum += arr[index];
        if(sum%(currCount+1) == 0 && sum/(currCount+1) == a){
           opt1++;
        }
        sum -= arr[index];
        dp[index][currCount][sum] = opt1 + opt2;
        return opt1 + opt2;
}
int32_t main(){
   cin>>n>>a;
   int arr[n];
   rep(i, 0, n){
       cin>>arr[i];
   }
   memset(dp, -1, sizeof(dp));
   cout<<solve(arr, 0, 0, 0)<<endl;
}
