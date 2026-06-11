#include <iostream>
using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;
  int path[n] = {0};
  for(int i = 0; i < m; ++i){
    int a, b;
    cin >> a >> b;
    path[a-1]++;
    path[b-1]++;
  }
  
  for(int i = 0; i < n; ++i){
    cout << path[i] << endl;
  }
}