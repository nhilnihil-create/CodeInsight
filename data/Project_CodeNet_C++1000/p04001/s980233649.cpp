#include <bits/stdc++.h>
using namespace std;

int main(){
  int64_t N,M=0;
  int sum=0;
  cin>>N;
  int64_t n=N;
  while(!(n/10==0)){
    sum++;
    n /=10;
  }
  int c=pow(2, sum);
  for(int tmp=0;tmp<c;tmp++){
    bitset<9> A(tmp);
    int64_t s=N;
    int t=1;
    for(int i=0;i<sum;i++){
      if(A.test(i)){
        int64_t a=pow(10, t);
        M +=s%a;
        s /=a;
        t =1;
      }
      else t++;
    }
    M +=s;
  }
  cout<<M<<endl;
}
