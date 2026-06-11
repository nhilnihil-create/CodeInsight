#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,a=0,b=0,c=0;
  cin>>N;
  for(int i=0;i<N;i++){
    int A;
    cin>>A;
    if(A%4==0)
      a++;
    else if(A%2==0)
      b++;
    else
      c++;
  }
  if(c<=a)
    cout<<"Yes"<<endl;
  else if(c==a+1 && b==0)
    cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;
}
