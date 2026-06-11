#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

main(){
  int n,t,s=0,f1,f2;
  cin>>n>>t;
  cin>>f1;
  for(int i=0;i<n-1;i++){
    cin>>f2;
    s +=min(t,f2-f1);
    f1 = f2;
  }
  cout<<s+t<<endl;
  return 0;
}