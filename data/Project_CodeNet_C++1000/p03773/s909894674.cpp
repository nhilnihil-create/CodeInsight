 #include <iostream>
using namespace std;

int main()
{
   int a,b,c=0;
   cin>>a>>b;
   c=a+b;
   if(c<24)
    cout<<c;
    else if(c==24)
        cout<<0;
   else {
        c-=24;
   cout<<c;
   }
    return 0;
}