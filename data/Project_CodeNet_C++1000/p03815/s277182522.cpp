#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t x;
  cin>>x;
  cout<<x/11*2+(x%11<=6?(x%11==0?0:1):2)<<endl;
}