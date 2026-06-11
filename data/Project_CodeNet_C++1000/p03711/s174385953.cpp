#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  int x,y;
  cin>>x>>y;
  int vec[13]={0,1,3,1,2,1,2,1,1,2,1,2,1};
  if(vec[x]==vec[y]){
      cout<<"Yes"<<endl;
    }
  else{
      cout << "No" << endl;
    }
}
