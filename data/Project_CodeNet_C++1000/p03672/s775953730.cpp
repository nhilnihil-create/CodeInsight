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
string s; cin>>s;
int i = s.size() - 1;
while(true){
    if(i % 2 == 0){
        if(s.substr(0, i/2) == s.substr(i/2, i/2)){
            cout << i << endl;
            break;
         }
      }
      i--;
   }
return 0;
}