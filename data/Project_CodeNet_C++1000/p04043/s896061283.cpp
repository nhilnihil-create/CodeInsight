#include <bits/stdc++.h>
#include <iostream>
#include<math.h>
#include<cmath>
#include<string>
#include<iomanip>
#include <numeric>
#include <limits>
using namespace std;
 
int main()
{
int a,b,c; cin>>a>>b>>c;
if((a+b+c)==17)
{
    if(a==7||b==7||c==7)
        if(a==5||b==5||c==5)
         cout<<"YES";
         else cout<<"NO"; 
    else cout<<"NO";
}
else cout<<"NO";
return 0;
}