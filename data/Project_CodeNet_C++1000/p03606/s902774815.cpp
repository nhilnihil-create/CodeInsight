#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin>>N;
  int sum=0;
  for(int i=0;i<N;i++){
    int a;
    int b;
    cin>>a>>b;
    sum+=b-a+1;
  }
  cout<<sum<<endl;

}
