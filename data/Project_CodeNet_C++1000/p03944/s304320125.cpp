#include <iostream>
#include <vector>

using namespace std;

int main()	{
  int w, h, n;
  cin >> w >> h >> n;
  int x;
  int y;
  int a;
  int xmin = 0, ymin = 0;
  int xmax = w, ymax = h;
  for (int i = 0; i < n; i++)	{
    cin >> x >> y >> a;
    switch(a)	{
      case 1: xmin = max(xmin, x);
        	break;
      case 2: xmax = min(xmax, x);
        	break;
      case 3: ymin = max(ymin, y);
        	break;
      case 4: ymax = min(ymax, y);
        	break;
    }
  }
  if (xmin >= xmax || ymin >= ymax)	{
  	cout << 0 << endl;
    return 0;
  }
  cout << (xmax - xmin) * (ymax - ymin) << endl;
  return 0;
}