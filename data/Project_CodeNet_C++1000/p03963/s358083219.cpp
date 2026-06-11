#include<bits/stdc++.h>
#include <string> 

using namespace std;
int X,N;
int A[2000010]{};

int main()
{
  cin>>N>>X;
  int ans=X;
  for(int i=1;i<N;i++){
    ans*=X-1;
  }

  cout<<ans;
  return 0;
}



