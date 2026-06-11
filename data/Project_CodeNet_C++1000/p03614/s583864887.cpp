#include <bits/stdc++.h>

using namespace std;

#define rep(i,m,n) for(int i=m;i<n;i++)


int main(){
 long n;
   cin >> n;

 vector<long> p(n);
  rep(i,0,n) cin >> p[i];
   
  long res=0;
  rep(i,0,n-1){
   if(p[i]==i+1) {
     swap(p[i],p[i+1]);
     res++;
   }
  }
  if(p[n-1]==n) res++;
  
  cout << res << endl;
  
}