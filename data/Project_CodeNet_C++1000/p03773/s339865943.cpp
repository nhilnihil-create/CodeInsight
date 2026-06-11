 #include <iostream>
 #include <math.h>
 #include <bits/stdc++.h>
  using namespace std;

 int main()
     {
  int a,b,c;
  cin>>a>>b;
  c=a+b;
  if(c<24)
    cout<<c;
    else if(c==24)
        cout<<0;

  else cout<<c-24;


   return 0;
     }
