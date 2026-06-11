#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define all(a) a.begin(), a.end()
#define x first
#define y second
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef double ld;

int main() {
  int n;
  cin >> n;
  vector<int> nums;
  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;
    nums.push_back(temp);
  }
  int min_cost = INF;
  int answer;
  sort(nums.begin(), nums.end());
  // for (int i = 0; i < n; i++) cout << nums[i] << " ";
  // cout << endl;
  for (int i = nums[0]; i <= nums[n - 1]; i++) {
    // cout << i << " ";
    int current = i;
    int current_cost = 0;
    // cout << "Current : " << current_cost << endl;
    for (int j = 0; j < n; j++) {
      current_cost += (current - nums[j]) * (current - nums[j]);
    }
    if (current_cost < min_cost) {
      min_cost = current_cost;
      answer = i;
    }
    // cout << "Current : " << current_cost << endl;
  }
  // cout << min_cost << " " << answer << endl;
  cout << min_cost << endl;
}