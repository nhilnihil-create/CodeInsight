#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;

int N;
ll C, K;
ll arr[100005];

int solve(int count) {
      sort(arr, arr+N);
      int start = arr[0];
      int bus = 1; 
      for(int i=1; i<N; i++) {
            if(arr[i] <= (start + K) && bus < C) {
                  bus++;
            }
            else {
                  count++;
                  bus = 1;
                  start = arr[i]; 
            }
      } 
      return count;
}

int main() {
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      cout.tie(NULL);

      cin >> N >> C >> K;

      for(int i=0; i<N; i++) {
            cin >> arr[i];
      }

      cout << solve(1) << endl;
}