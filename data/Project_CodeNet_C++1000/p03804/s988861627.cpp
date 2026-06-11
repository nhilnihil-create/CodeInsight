#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()

typedef long long ll;

const char nl = '\n' ;
int N, M;
char a[51][51];
char b[51][51];

bool check(int x, int z)
{
   int tmp = z;
   for(int i = 1; i <=  M; i++, x++)
   {
      for(int j = 1, z= tmp; j <= M; j++, z++)
      {
         if(a[x][z] != b[i][j])
         {
            return false;
         }

      }
   }
   return true;
}
int main()
{
   ios_base::sync_with_stdio(0); cin.tie(0);
   cin >> N >> M;
   for(int i = 1; i <= N; i++)
   {
      for(int j = 1; j <= N; j++)
         cin >> a[i][j];
   }

   for(int i = 1; i <= M; i++)
   {
      for(int j = 1; j <= M; j++)
         cin >> b[i][j];
   }
   for(int i =1; i <= N-M+1; i++)
   {
      for(int j = 1; j <= N-M+1; j++)
      {
         if(check(i, j))
         {
            cout << "Yes" << nl;
            return 0;
         }
      }
   }
   cout << "No" <<nl;
   return 0;


}
