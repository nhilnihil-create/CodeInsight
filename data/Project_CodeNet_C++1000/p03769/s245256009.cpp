#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

deque< int > latte, malta;
int num;

void dfs(int64 p)
{
  if(p == 1) return;
  if(p & 1) dfs(p - 1), latte.push_front(num), malta.push_back(num++);
  else dfs(p / 2), latte.push_back(num), malta.push_back(num++);
}

int main()
{
  int64 N;
  cin >> N;

  num = 1;
  dfs(++N);

  cout << latte.size() + malta.size() << endl;
  for(int i = 0; i < latte.size(); i++) {
    cout << latte[i] << " ";
  }
  for(int i = 0; i < malta.size(); i++) {
    cout << malta[i] << " ";
  }
  cout << endl;
}