#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef vector<int> vec;
long de(long a,long x){
  if(a==-1) return 0;
  return a/x+1;
}
int main(){
  long a,b,x;cin>>a>>b>>x;
  cout<<de(b,x)-de(a-1,x)<<endl;

}