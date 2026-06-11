#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int,int> ii;

const int N = 1e5 + 5;

int n,a[N];
bool flag;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cin >> n;
  for (int i = 1 ; i <= n ; i++)
    cin >> a[i];
  sort(a + 1 , a + n + 1,greater <int>());
  for (int i = 1 ; i <= n ; i++) {
    if (i + 1 > a[i + 1]) {
      int go = i;
      while (go < n && a[go + 1] >= i)
        go++;
      if ((a[i] - i) % 2 == 1 || (go - i) % 2 == 1)
        cout << "First\n";
      else
        cout << "Second\n";
      return 0;
    }
  }

}