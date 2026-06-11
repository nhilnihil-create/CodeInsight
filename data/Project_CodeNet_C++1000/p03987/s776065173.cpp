# include <bits/stdc++.h>
using namespace std;

/* 
  idea : for each number, find the leftmost and rightmost point 
  which this number can be the minimum value in that range

  and add that l * r * number to our sum
*/

int main(){
  int n, arr[200005], left[200005], right[200005];
  cin >> n;
  for(int i=1; i<=n; i++){
    cin >> arr[i];
  }

  vector<int> stack;
  for(int i=1; i<=n; i++){
    while(!stack.empty() && arr[stack.back()] >= arr[i]) stack.pop_back();
    left[i] = (stack.empty() ? i : i - stack.back());
    stack.push_back(i);
  }

  stack.clear();
  for(int i=n; i>=1; i--){
    while(!stack.empty() && arr[stack.back()] >= arr[i]) stack.pop_back();
    right[i] = (stack.empty() ? (n-i+1) : stack.back()-i);
    stack.push_back(i);
  }

  long long ans = 0;
  for(int i=1; i<=n; i++) ans += 1ll * left[i] * right[i] * arr[i];
  cout << ans << endl;
  return 0;
}