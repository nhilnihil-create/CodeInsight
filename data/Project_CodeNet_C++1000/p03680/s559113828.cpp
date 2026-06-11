#include <bits/stdc++.h>

#include <stdio.h>
#include <iostream>
#include <stddef.h>
 
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0); 

  int n; cin >> n;
  int arr[n + 1];

  for (int i = 1; i <= n; ++i) cin >> arr[i];

  bool visited[n + 1];
  memset(visited, false, sizeof(visited));

  int buttons_pressed = 0;
  queue<int> q({1});

  while (!q.empty()) {
    int x = q.front(); q.pop();

    if (x == 2) {
      cout << buttons_pressed << "\n";
      return 0;
    }

    if (!visited[x]) {
      visited[x] = true;
      buttons_pressed++;
      q.push(arr[x]);
    }
  }

  cout << -1 << "\n";
}
