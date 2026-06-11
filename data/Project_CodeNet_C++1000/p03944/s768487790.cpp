#include <bits/stdc++.h>
using namespace std;
int main()
{
   int w, h, n, x, y, a;
   cin >> w >> h >> n;
   int x_max=w;
   int x_min=0;
   int y_max=h;
   int y_min=0;
   for(int i=0;i<n;i++) {
     cin >> x >> y >> a;
     if ((a==2) && (x_max > x)) x_max=x;
     if ((a==1) && (x_min < x)) x_min=x;
     if ((a==4) && (y_max > y)) y_max=y;
     if ((a==3) && (y_min < y)) y_min=y;
   }
   if ((x_max < x_min) || (y_max < y_min)) cout << 0 << endl;
   else cout << (x_max - x_min) * (y_max - y_min) << endl;
}