#include<bits/stdc++.h>
#include <string> 

using namespace std;
int A,B,C;
int main()
{
  cin>>A>>B>>C;
  for(int i=1;i<=1000;i++){
  	if((i*A)%B==C){
      cout<<"YES";
      return 0;
    }
  }
  cout<<"NO";
  return 0;
}
