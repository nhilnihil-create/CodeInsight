#include <bits/stdc++.h>
using namespace std;

int main()
{
   int h, w;
   cin >> h >> w;
   vector<vector<char>>a(h,vector<char>(w));
   for(int i = 0;i < h; i++){
      for(int j = 0; j < w; j++)cin >> a[i][j];
   }
   for(int i = 0; i < w+2; i++)cout << "#";
   cout << endl;
   for(int i = 0; i < h; i++){
      cout << "#";
      for(int j = 0; j < w; j++)cout << a[i][j];
      cout << "#";
      cout << endl;
   }
   for(int i = 0; i < w+2; i++)cout << "#";
   cout << endl;

}
