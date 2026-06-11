#include <iostream>
using namespace std;
int main(void){
   
   int a,b,c,d;
   cin>>a>>b>>c>>d;
   
   int k=max(a,c);
   int h=min(b,d);
   int s=h-k;
   cout<<max(0,s)<<endl;
}