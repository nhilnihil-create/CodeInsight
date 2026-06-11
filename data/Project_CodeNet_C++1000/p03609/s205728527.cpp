#include<bits/stdc++.h>
using namespace std;
void sand(int x, int t){
       if(x>t){
        cout<<(x-t)<<endl;
       }
       if(x<=t){
        cout<<0<<endl;
       }
}
int main(){
  unsigned long long int x,t;
  cin>>x>>t;
  sand(x,t);
  return 0;
}
