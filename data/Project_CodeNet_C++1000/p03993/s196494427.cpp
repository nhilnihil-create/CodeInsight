#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  vector<int> a(N);
  for(int &i:a){
    int j;
    cin>>j;
    i=j-1;
  }
  int j=0;
  for(int i=0;i<N;i++)
    if(i==a[a[i]])
      j++;
  cout<<j/2<<endl;
}