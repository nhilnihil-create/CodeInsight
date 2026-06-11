#include<bits/stdc++.h>
using namespace std;
int main(){
  vector<int>A(3);
  for(int i=0;i<3;i++)cin>>A[i];
  count(A.begin(),A.end(),5)==2&&count(A.begin(),A.end(),7)==1?puts("YES"):puts("NO");
}