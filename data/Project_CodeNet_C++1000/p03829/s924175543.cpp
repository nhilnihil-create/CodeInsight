#include <bits/stdc++.h>
#include<math.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
  long N,A,B;
  cin>>N>>A>>B; 

  vector<int>a(N);
  for (int i = 0; i < N; i++) {
    cin>>a.at(i);
  }
  vector<long>b(N);
  b.at(0)==0;
  for (int i = 1; i < N; i++) {
    b.at(i)=min(b.at(i-1)+A*(a.at(i)-a.at(i-1)),b.at(i-1)+B);
  }
   
  
      cout<<b.at(N-1)<<endl;
 
}