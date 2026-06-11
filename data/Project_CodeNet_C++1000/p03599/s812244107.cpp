#include<bits/stdc++.h>
#include<iomanip>
using namespace std;
int main(){
  double a,b,c,d,e,f;
  cin >> a >> b>> c >> d>> e>> f;
  double howa = e*100/(e+100);
  double ans = 0;
  double A,B ; //あとの要素を入れ子にしていくというてく
  for(int i = 0; i <=f; i+= 100*a){
    for(int j = 0; i+j <= f; j+= 100*b){
      for(int k = 0; i+j+k <= f; k+= c){
        for(int l = 0; i+j+k+l<=f; l+=d){
          double eki = i+j+k+l;
          double sato = k+l;
          if(eki != 0){
           double intensity = sato*100/eki;
              if(intensity <= howa  && ans <= intensity){
              ans = max(ans,intensity) ;
              A = eki;
              B = sato;
            }
             }
            }
          }
        }
      }
cout << A << " "<< B << endl;
}

