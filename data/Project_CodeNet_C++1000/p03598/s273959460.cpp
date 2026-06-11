#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<math.h>

using namespace std;

int main()
{
   int n, k, ans, total = 0;

   cin >> n >> k;

   vector<int> xv;

   for(int i = 0; i < n; i++)
   {
      int x;
      cin >> x;
      xv.push_back(x);
   }

   for(int i = 0; i < n; i++)
   {
      ans = min(xv[i],abs(xv[i] - k));
      //cout << ans << endl;
      total = total + ans*2;
   }

   cout << total;
}