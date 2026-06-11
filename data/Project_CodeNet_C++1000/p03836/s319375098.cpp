#include <bits/stdc++.h>
using namespace std;

#define froop1(a,n) for(int i = a;i < n;i++)
#define froop2(a,n) for(int i = a;i > n;i--)
int main(){
	int x1,y1,x2,y2;
  cin >> x1 >> y1 >> x2 >> y2;
  int dx = abs(x1-x2);
  int dy = abs(y1 - y2);
  cout << string(dy,'U') << string(dx,'R');
  cout << string(dy,'D') << string(dx,'L');
  cout << 'L' << string(dy + 1,'U') << string(dx + 1,'R') << 'D';
  cout << 'R' << string(dy + 1,'D') << string(dx + 1,'L') << 'U' << endl;

return 0;
}