#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

void failure () {
  cout << "NO" << endl;
  exit(0);
}

const int MAX_N = 1e5 + 5;

vector<int> adj [MAX_N];
int arr [MAX_N];

ll dfs (int u, int p) {
  if ((int) adj[u].size() == 1) {
    return arr[u];
  }

  ll sum = 0, mx = 0;
  for (int nxt : adj[u]) {
    if (nxt != p) {
      ll nval = dfs(nxt, u);
      sum += nval;
      mx = max(mx, nval);
    }
  }

  if (p == 0) {
    if (2 * mx > sum) {
      failure();
    }
    
    if (sum != 2 * arr[u]) {
      failure();
    }
    return 0LL;
  } else {
    ll diff = sum - arr[u];
    if (diff < 0) failure();
    if (sum - 2 * diff < 0) failure();
    // diff is the number of pairs we match
    // we must be able to do this without needing
    // to take a pair from mx
    if (sum - mx < diff) failure();
    
    return sum - 2 * diff;
  }
}

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  if (n == 2) {
    if (arr[1] == arr[2]) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
    return 0;
  }

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int root = -1;
  for (int i = 1; i <= n; i++) {
    if (adj[i].size() != 1) {
      root = i;
    }
  }

  dfs(root, 0);
  cout << "YES" << endl;
}
