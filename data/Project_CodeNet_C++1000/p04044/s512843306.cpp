#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
  ios_base :: sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, l;
  cin >> n >> l;
  vector<string> v(n);
  int i;
  for(i=0; i<n; i++){
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  for(auto it = v.begin(); it!=v.end(); it++){
    cout << *it;
  }
  cout << '\n';
  return 0;
}
