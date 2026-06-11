#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int a,b,c,d,e,f;
  cin >> a >> b >> c >> d >> e >> f;
  double Max=0;
  int all=0, sato=0;
  for(int i=0; i<100; i++){
    for(int j=0; j<100; j++){
    if(i+j==0) continue;
     for(int k=0; k<200; k++){
      for(int l=0; l<200; l++){
        double x = (c*k+d*l)*1000000/(a*i+b*j);
        if(a*i*100+b*j*100+c*k+d*l<=f && x/1000000 <=e&& x>=Max){
          Max=x;
          all=a*i*100+b*j*100+c*k+d*l;
          sato=c*k+d*l;
        }
     } 
    }
   } 
  }
  
  cout << all << " " << sato << endl;
  
}
