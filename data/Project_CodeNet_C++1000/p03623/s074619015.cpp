#include<bits/stdc++.h>
using namespace std;

int main(void){
   int x,a,b;
   cin>>x>>a>>b;
   int dist_1=abs(x-a);
   int dist_2=abs(x-b);
   if(dist_1<dist_2) cout<<"A"<<endl;
   else cout<<"B"<<endl;
   return 0;
}

