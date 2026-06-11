#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793

int main(){
   string s;
   cin >> s;
   int n=s.size();
   set<char> chk;
   bool c=true;
   rep(i,n){
      if(chk.count(s.at(i))){
         c=false;
         break;
      }
      else{
         chk.insert(s.at(i));
      }
   }
   if(c)cout <<"yes" << endl;
   else cout << "no" << endl;
}
