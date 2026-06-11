#include <bits/stdc++.h>
using namespace std;

int main()
{
  int L, N;
  cin >> N >> L;

  priority_queue<string, vector<string>, greater<string>> pq;

  for (int i = 0; i < N; i++)
  {
    string tmp;
    cin >> tmp;
    pq.push(tmp);
  }

  for (int i = 0; i < N; i++)
  {
    cout << pq.top();
    pq.pop();
  }
  cout << endl;
}