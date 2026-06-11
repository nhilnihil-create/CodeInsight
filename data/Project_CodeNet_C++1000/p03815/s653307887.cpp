#include <bits/stdc++.h>
#include<math.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
  long x;
  cin>>x; 
    if(x%11==0){
      cout<<2*(x/11)<<endl;
    }else if(x%11<=6){
      cout<<2*(x/11)+1<<endl;
    }else{
      cout<<2*(x/11)+2<<endl;
    }
 
  
 
}







