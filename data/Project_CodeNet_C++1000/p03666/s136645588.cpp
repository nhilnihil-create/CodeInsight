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
   long long N;
   cin >> N;
   long long A,B,C,D;
   cin >> A >> B >> C >> D;
   if(A>B) swap(A,B);
   long long F = B-A;
   N--;
   bool ok = false;
   long long cnt = 0;
   for(int n = N; n >= 0; n-=2){
      long long highest = n*D; 
      long long lowest = n*C;
      highest += cnt*(D-C);
      lowest -= cnt*(D-C);
      //cout << highest <<" - " << lowest << endl;
      if(lowest <=F && F <= highest){
         ok = true;
         break;
      }
      cnt++;
   }
   if(ok){
      cout << "YES" << endl;
   }
   else{
      cout << "NO" << endl;
   }


   return 0;
}
