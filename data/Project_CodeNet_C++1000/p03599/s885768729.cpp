#include <bits/stdc++.h>
using namespace std;



  
int main(){
  

  int a,b,c,d,e,f;
  cin>>a>>b>>c>>d>>e>>f;
  
  int water=0;
  int sugar=0;
  double densitymax=0;
  
  for (int i=0;i<=f/(100*a);i++){
    for (int j=0;j<=(f-100*a*i)/(100*b);j++){
      int idealsugar;
      idealsugar=min(e*(a*i+b*j),f-100*a*i-100*b*j);   
      for (int k=0;k<=idealsugar/c;k++){
        int l;
        l=(idealsugar-c*k)/d;
        double density=(c*k+d*l+0.0)/(a*i+b*j);
        if (density>=densitymax){
          densitymax=density;
          water=100*(a*i+b*j);
          sugar=(c*k+d*l);
        }
      }
    }
  }
  
  cout<<water+sugar<<" "<<sugar<<endl;

        
}

    









