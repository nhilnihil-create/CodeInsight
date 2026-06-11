#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int N;
  cin >> N;
  
  int seat = 0;
  rep(i, N)
  {
	int l, r;
    cin >> l >> r;
    
    seat += r - l + 1;
  }
  
  cout << seat << endl;
}
