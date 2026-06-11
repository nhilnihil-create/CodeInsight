#include <bits/stdc++.h>
using namespace std;

int main() {
   int n;
   string s,t;
   cin>>n>>s>>t;
   int result=2*n;
   int max=0;
   for(int i=1;i<=n;i++){
       int loop=1;
       for(int j=1;j<=i;j++){
           if(s.at(n-i-1+j)==t.at(j-1)){
               continue;
           }else{
               loop=0;
               break;
           }

       }
       if(loop==0) continue;
       else if(max<i) max=i;
   }
   cout<<2*n-max<<endl;
}