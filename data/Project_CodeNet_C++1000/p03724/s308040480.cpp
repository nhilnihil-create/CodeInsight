#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,M;
  cin>>N>>M;
  vector<int> A(N);
  for(int i=0;i<M;i++){
    int a,b;
    cin>>a>>b;
    A[a-1]++,A[b-1]++;
  }
  for(int &i:A)
    if(i%2==1){
      puts("NO");
      return 0;
    }
  puts("YES");
}