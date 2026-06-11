# include <bits/stdc++.h>
using namespace std;
# define ll long long 

ll getSum(ll arr[], int l, int r){
  if(l > r) return 0;
  return arr[r] - arr[l-1];
}

int main(){
  int n, k;
  ll sum[100005], positiveSum[100005];
  sum[0] = positiveSum[0] = 0;

  cin >> n >> k;
  for(int i=1; i<=n; i++){
    int x; cin >> x;
    sum[i] = sum[i-1] + x;
    positiveSum[i] = positiveSum[i-1] + max(x, 0);
  }

  ll ans = 0;
  for(int i=1; i+k-1 <= n; i++){
    int left = i;
    int right = i+k-1;
    ans = max(ans, 
        getSum(positiveSum, 1, left-1) + 
        max(0ll, getSum(sum, left, right)) + 
        getSum(positiveSum, right+1, n)
    );
  }

  cout << ans << endl;
  return 0;
}