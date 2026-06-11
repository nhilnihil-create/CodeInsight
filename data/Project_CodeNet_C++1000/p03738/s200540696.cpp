#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793

int main(){
  string a,b;
  cin >> a >> b;
  int n=a.size();
  int m=b.size();
  string ans;
  if(n>m)ans="GREATER";
  else if(n<m)ans="LESS";
  else if(n==m){
     bool c=true;
     rep(i,n){
        int aa=a.at(i)-'0';
        int bb=b.at(i)-'0';
        if(aa>bb){
           ans="GREATER";
           c=false;
           break;
        }
        else if(bb>aa){
           ans="LESS";
           c=false;
           break;
        }
     }
     if(c)ans="EQUAL";
  }
   cout << ans << endl;
}