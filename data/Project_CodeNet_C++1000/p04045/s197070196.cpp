#include <bits/stdc++.h>
using namespace std;
bool checker(int n,int A[],int k){
int noOfdigits = floor(log10(n)+1);
for(int i=0;i<noOfdigits;i++){
   int digit = n%10;
   for(int j=0;j<k;j++){
      if(digit==A[j]) return false;
   }
   n/=10;
}
return true;
}
int main(){
   // We have to Find the Closest digit to N that does not contain any of those K digits
   // Brute Force
   int n,k,res;
   cin>>n>>k;
   int A[k];
   for(int i=0;i<k;i++) cin>>A[i];
   res=n;
   while(checker(res,A,k) != true){
     res++;
   }
   cout<<res;
   return 0;
}

