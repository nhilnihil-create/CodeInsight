 #include <iostream>
 #include <math.h>
 #include <bits/stdc++.h>
  using namespace std;

 int main()
     {
    int a,b,x,d1,d2;
    cin>>x>>a>>b;
    d1=abs(x-a);
    d2=abs(x-b);
    if(d1<=d2)
        cout<<"A";
    else cout<<"B";

   return 0;
     }
