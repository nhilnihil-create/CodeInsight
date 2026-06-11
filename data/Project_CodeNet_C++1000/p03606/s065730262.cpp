#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,x=0,y=0;
  cin >> N;
  for(int i=0; i<N; i++){
    int a,b;
    cin >> a >> b;
    x=b-a+1;
    y+=x;
  }
  cout << y << endl;
}