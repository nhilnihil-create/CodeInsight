#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) FOR(i,0,n)
typedef long long ll;
int main(){
  int n;
  vector<int> buttons;
  
  cin >> n;
  rep(i,n) {
	int a;
    cin >> a;
    buttons.push_back(--a);
  }
  
  int current = 0;
  int next = -1;
  rep(i,n) {
    next = buttons[current];
    if (next == 1) {
		cout << i+1 << endl;
      return 0;
    }
    current = next;
  }
  cout << "-1" << endl;
  return 0;
}