#include <iostream>
#include <stack>
using namespace std;

// number of odd numbers is even
// number of even numbers doesn't matter

int main() {
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      cout.tie(NULL);

      int N, odd = 0;
      cin >> N;
      int arr[N];
      for(int i=0; i<N; i++) {
            cin >> arr[i];
            if(arr[i]%2 != 0) odd++;
      }

      if(odd%2 == 0) cout << "YES" << endl;
      else cout << "NO" << endl;
}