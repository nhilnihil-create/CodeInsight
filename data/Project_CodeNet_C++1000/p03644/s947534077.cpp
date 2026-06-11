#include<iostream>
using namespace std;

int countdiv(int n) {
  int count=0;
  
  for(int i=n; i>0; i/=2) {
    if(i%2 == 0) count++;
  }
  
  return count;
}

int main(){
  int N,count,maxcount=0,maxnumber;
  
  cin >> N;
  
  for(int i=1; i<=N; i++) {
    count = countdiv(i);
    if(maxcount <= count) {
      maxcount = count;
      maxnumber = i;
    }
  }
  
  cout << maxnumber << endl;
  
  return 0;
}