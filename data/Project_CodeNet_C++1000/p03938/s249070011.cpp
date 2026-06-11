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
   int N;
   cin >> N;
   vector<int> p(N);
   vector<int> q(N);
   vector<int> a(N);
   vector<int> b(N);
   for (int i = 0; i < N; i++)
   {
      cin >> p[i];
      q[p[i]-1]=i;
   }
   a[0]=1;
   b[0]=q[0]-a[0];
   for(int i = 1 ; i < N; i++){
      a[i]=a[i-1]+1;
      b[i]=q[i]-a[i];
      if(b[i]>=b[i-1]){
         int diff = b[i]-b[i-1]+1;
         b[i]-=diff;
         a[i]+=diff;
      }
   }
   int offset = max(0, 1-b[N-1]);

   for(int i = 0 ; i < N;i++){
      cout << a[i] << " ";
   }
   cout << endl;
   for(int i = 0 ; i < N;i++){
      cout << offset + b[i] << " ";
   }
   cout << endl;
   return 0;
}
