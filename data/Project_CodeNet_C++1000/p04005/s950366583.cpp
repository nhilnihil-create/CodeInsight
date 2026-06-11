#include <bits/stdc++.h>
#include <string>
using namespace std;
int main(){
  long long int A,B,C;
  cin>>A>>B>>C;
  long long int var1,var2,var3,var4,var5,var6;
  long long int diff1,diff2,diff3;
  long long int less;
 if(A>=2&&B>=2&&C>=2&&A<=1000000000&&B<=1000000000&&C<=1000000000){
  var1=A*B*(C/2);
  var2=A*B*(C-(C/2));
  var3=A*C*(B/2);
  var4=A*C*(B-(B/2));
  var5=B*C*(A/2);
  var6=B*C*(A-(A/2));
  diff1=abs(var1-var2);
  diff2=abs(var3-var4);
  diff3=abs(var5-var6);
  less=min(diff1,diff2);
  cout<<min(less,diff3);
 }
  return 0;
}
