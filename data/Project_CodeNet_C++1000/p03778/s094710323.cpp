#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <set>

using namespace std;

int main() {
  
    int w,a,b ;
    cin>>w>>a>>b ;

    int tmp = a+w ;

    if(tmp>=b && b>=a)
     cout << 0 << endl ;
    else if(b>tmp)
     cout << b-tmp << endl ;         
    else 
     cout << a-(b+w) << endl ;         
    
  return 0 ;
}