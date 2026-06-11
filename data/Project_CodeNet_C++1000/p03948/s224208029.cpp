#include <bits/stdc++.h>

using namespace std;

int main(){
 long n,t;
   cin >> n >> t;
 
  vector<long> b(n);
  
  long a;
  cin >>a;
  long num=a;
  b[0]=0;
  
  for(int i=1;i<n;i++){
    cin >> a;
    b[i]=a-num;
    num=min(num,a);
  }

  sort(b.begin(),b.end());
  
  cout <<upper_bound(b.begin(),b.end(),b[n-1])-lower_bound(b.begin(),b.end(),b[n-1]) << endl;
     

}