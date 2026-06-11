#include <bits/stdc++.h>
using namespace std;

int n;
int M[305][305];
int main()
{
   ios_base::sync_with_stdio(false);
   cin >> n;
   for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
         cin >> M[i][j];

   long long cost = 0;
   for (int i = 1; i <= n; i++)
      for (int j = i + 1; j <= n; j++)
      {
         bool ok = 0;
         for (int k = 1; k <= n; k++)
         {
            if (i == k || j == k)
               continue;
            if (M[i][k] + M[k][j] < M[i][j])
            {
               cout << -1;
               return 0;
            }
            if (M[i][k] + M[k][j] == M[i][j])
               ok = 1;
         }
         if (!ok) // nu avem intermediar
            cost += M[i][j];
      }
   cout << cost;
   return 0;
}
