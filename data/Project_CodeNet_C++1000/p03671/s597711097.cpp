#include<bits/stdc++.h>
using namespace std;
int main(){
vector<int>A(3);
  for(int i=0;i<3;i++)
    cin>>A.at(i);
  sort(A.begin(),A.end());
  int ans=(A[0]+A[1]);
  cout<<ans<<endl;
   return 0;
}