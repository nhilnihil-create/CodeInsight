#include <bits/stdc++.h>

using namespace std;


bool prime (int n){

    for(int i=2;i*i<=n;i++){
        if(n%i==0)  return false;
    }

    return true;
}


int main() {

   int n,m;
   cin>>n>>m;

   if(n==m)cout<<"Draw"<<endl;
   else if(n==1)cout<<"Alice"<<endl;
   else if(m==1)cout<<"Bob"<<endl;
   else if (n>m)cout<<"Alice"<<endl;
   else cout<<"Bob"<<endl;

    return 0;
}
