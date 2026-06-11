#include <iostream>
using namespace std;

int main() {
   int a,b,c;
   cin>>a>>b>>c;

   int a1,b1,c1;
   a1=a+b;
   b1=a+c;
   c1=(b+c);

   if(a1<c1&&a1<b1){
    cout<<a1<<endl;
   }
   else if(b1<a1&&b1<c1){
    cout<<b1<<endl;
   }
   else {
    cout<<c1<<endl;
   }



    return 0;
}
