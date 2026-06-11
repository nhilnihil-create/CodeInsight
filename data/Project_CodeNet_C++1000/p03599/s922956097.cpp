#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c,d,e,f;
  cin >> a >> b >> c >> d >> e >> f;
  double conc=0;
  int i_a=0;int j_a=0;int k_a=0;int l_a=0;
  for (int i=0; i<=f/100/a; i++){
    for (int j=0; j<=(f-i*100*a)/100/b; j++){
      int k = 0;
      while(f-i*100*a-j*100*b-c*k>=0 && e*(a*i+b*j)>=c*k){
        int l = 0;
        
        while(f-i*100*a-j*100*b-c*k-d*l>=0 && e*(a*i+b*j)>=c*k+d*l){
          if (i==0 && j==0) break;
          double conc_tmp = 100.0*(c*k+d*l)/(100*a*i+100*b*j+c*k+d*l);
          if(conc <= conc_tmp){
            conc=conc_tmp;
            i_a=i;j_a=j;k_a=k;l_a=l;
          }
          l++;
        }
        k++;
      }
    }
  }
  cout << 100*(a*i_a+b*j_a)+c*k_a+d*l_a << " " << c*k_a+d*l_a << endl;
}