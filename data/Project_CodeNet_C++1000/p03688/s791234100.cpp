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
   int a[N];
   for (int i = 0; i < N; i++)
   {
      cin >> a[i];
   }
   sort(a,a+N);
   if(a[N-1]-a[0]>=2){
      cout << "No" << endl;
   }
   else{
      int n=0;
      int m=N;
      for(int i = 0 ; i< N; i++){
         if(a[i]==a[0]){
            n++;
            m--;
         }
      }
      if(m==0){
         if(N/2>=a[0]){
            cout <<"Yes"<< endl;
         }
         else if(a[0]==N-1){
            cout <<"Yes"<< endl;
         }
         else{
            cout <<"No"<< endl;
         }
      }
      else if(m==1){
         cout <<"No" << endl;
      }
      else{
         if(n-1+m/2>=a[0]&&a[0]>=n){
            cout << "Yes"<<endl;
         }
         else{
            cout <<"No"<<endl;
         }
      }
   }
   
   return 0;
}
