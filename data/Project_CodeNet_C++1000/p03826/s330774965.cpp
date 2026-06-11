#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,c,d,area_1,area_2;
    cin>>a>>b>>c>>d;
     area_1=a*b;
     area_2=c*d;

     if(area_1>=area_2)
      {
          cout<<area_1<<"\n";
      }
     else {
        cout<<area_2<<"\n";
     }

    return 0;
}
