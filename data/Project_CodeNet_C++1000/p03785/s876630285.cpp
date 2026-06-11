# include <iostream>
# include <algorithm>
using namespace std;

int main(){

  int n, c, k;
  cin >> n >> c >> k;

  int num[n+5];
  for(int i=0; i<n; i++) cin >> num[i];
  sort(num, num+n);

  int ans = 0;
  int left = 0, right = 0;
  while(left < n){
    ans++;

    while(right+1 < n && num[right+1] <= num[left]+k && (right+1 - left+1 <= c))
      right++;
    
    left = right+1;
    right = left;
  }

  cout << ans << endl;
  return 0;
}