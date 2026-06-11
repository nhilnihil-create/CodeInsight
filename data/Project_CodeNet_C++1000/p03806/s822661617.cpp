#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <cstring>
#include <iomanip>
#include <cassert>

using namespace std;
typedef long long ll;

int main(){
   int N, A,B;
   cin >> N >> A >> B;
   int a[N],b[N],c[N];
   int lowest[500][500];
   for(int i=0;i<500;i++){
      for (int j = 0; j < 500; j++)
      {
         lowest[i][j]=INT_MAX/2;
      }
   }
   lowest[0][0]=0;
   for (int i = 0; i < N; i++)
   {
      cin >> a[i] >> b[i] >> c[i];
      for(int x=499-a[i];x>=0;x--){
         for(int y=499-b[i];y>=0;y--){
            if(lowest[x][y]!=INT_MAX/2){
               lowest[x+a[i]][y+b[i]]=min(lowest[x+a[i]][y+b[i]], lowest[x][y]+c[i]);
            }     
         }
      }
   }
   int ans = INT_MAX/2;
   for(int i = 1 ; i < 500; i++){
      int X=A*i;
      int Y=B*i;
      if(X>400||Y>400){
         break;
      }
      ans = min(ans, lowest[X][Y]);
   }
   if(ans == INT_MAX/2) ans = -1;
   cout << ans << endl;
   
   return 0;
}
