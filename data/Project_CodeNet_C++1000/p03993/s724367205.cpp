#include<bits/stdc++.h>
#include <string> 

using namespace std;
int X,N;
int A[2000010]{};
bool B[2000010]{};

int main()
{
  cin>>N;
  for(int i=1;i<=N;i++)cin>>A[i];
  int count=0;
  for(int i=1;i<=N;i++){
    if(A[A[i]]==i)count++;
  }

  cout<<count/2;
  return 0;
}



