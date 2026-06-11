 #include <iostream>
 #include <math.h>
 #include <bits/stdc++.h>
  using namespace std;

 int main()
     {
  long long a,b,c;
  cin>>a>>b>>c;
   if(a==b&&a==c&&c==b)
    cout<<1;
   else if(a==b&&a!=c&&c!=b)
      cout<<2;
   else if(a!=b&&b==c&&c!=a)
    cout<<2;
   else if(a!=b&&a==c&&c!=b)
    cout<<2;
   else if(a!=b&&b!=a&&a!=c)
    cout<<3;
   return 0;
     }
