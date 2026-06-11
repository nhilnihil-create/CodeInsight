#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i < (int)(n);i++)

int main(){
   int n,t;
   cin >> n >> t;
   vector<int> v(n,0);
   ll sum=0;
   ll now=0;
   now=t;
   sum=t;
   ll s;
   cin >> s;
   rep(i,n-1){
     int tmp;
     cin >> tmp;
     if (now < tmp) {
       sum+=t;
       now=tmp+t;
     }
     else{
        sum+=(tmp+t)-now;
        now=tmp+t;
     }
   }
   cout << sum << endl;
   return 0;
}

