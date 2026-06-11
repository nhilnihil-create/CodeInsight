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
   int x;
   cin >> N >> x;
   if(x==1 || x == 2*N-1){
      cout << "No" << endl;
   }
   else{
      bool used[2*N];
      memset(used,false,sizeof(used));
      int ans[2*N-1];
      ans[N-1]=x;
      used[x]=true;
      int left =1;
      int right = 2*N-1;
      int dir = 1;
      cout << "Yes" << endl;
      for(int i = 1 ; i < N; i++){
         while(used[left])left++;
         while(used[right])right--;
         used[left]=true;
         used[right]=true;
         ans[N-1+i*dir]=left;
         ans[N-1-i*dir]=right;
         dir*=-1;
      }
      for(int i=0;i<2*N-1;i++){
         cout << ans[i]<< endl;
      }
   }
   return 0;
}
