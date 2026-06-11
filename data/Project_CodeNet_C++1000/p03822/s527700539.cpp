#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> graph[100010];

int search(int i){
  int ans = 0;

  vector<int> data;
  for(int j = 0;j < graph[i].size();j++){
    data.push_back(search(graph[i][j]));
  }

  sort(data.begin(), data.end(), greater<int>());

  for(int j = 1;j <= data.size();j++){
    ans = max(ans, data[j-1] + j);
  }

  return ans;
}

int main(){
  cin >> n;

  int a[100010];
  for(int i = 1;i < n;i++){
    cin >> a[i];
    a[i]--;
    graph[a[i]].push_back(i);
  }

  cout << search(0) << endl;

  return 0;
}