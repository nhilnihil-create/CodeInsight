#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin>>N;
  int num1=0, num2=0;
  for(int i=0; i<N; i++){
    int l=0, r=0;
    cin>>l>>r;
    num2=r-l+1;
    num1+=num2;
  }
  cout<<num1<<endl;
    
}
