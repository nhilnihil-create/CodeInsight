#include<bits/stdc++.h>
#include<cstdlib>
#include<cmath>
using namespace std;
int main(){
  int A; int B; int C; int D;
  cin>>A>>B>>C>>D;
 if(B<C||A>D)
   cout<<0<<endl;
  else{
    cout<<min(D,B)-max(A,C)<<endl;
  }
}
