#include<iostream>
using namespace std;
int main(){
  int N, M, x[100000], y[100000], n[100000], red[100000], cnt=0;
  cin >> N >> M;
  for(int i=0; i<M; i++){
    cin >> x[i] >> y[i];
  }

  for(int i=0; i<N; i++){
    n[i] = 1;
    red[i] = false;
  }
  red[0] = true;

  for(int i =0; i<M; i++){
    if(red[x[i]-1]) red[y[i]-1]=true;
    n[x[i]-1]--;
    n[y[i]-1]++;
    if(n[x[i]-1]==0) red[x[i]-1]=false;
  }

  for(int i=0; i<N; i++){
    if(red[i]) cnt++;
  }
  cout << cnt << endl;
  return 0;
}