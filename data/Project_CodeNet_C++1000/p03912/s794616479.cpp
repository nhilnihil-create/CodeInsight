#include<bits/stdc++.h>
using namespace std;

int N,M;
int T[100005];
int K[100005];
int Kk[100005];
int Kg[100005];
void del(int id){
  if( Kk[id] ) Kk[id]--;
  else {
    Kg[id]--;
    Kk[id]++;
  }
}
int main(){
  cin >> N >> M;
  for(int i=0;i<N;i++){
    int x; cin >> x;
    T[x]++;
    K[ x % M ]++;
  }
  for(int i=0;i<=100000;i++){
    Kg[ i%M ] += T[i]/2;
    Kk[ i%M ] += T[i]%2;
  }
  int res = 0;
  //  for(int i=0;i<M;i++) cout << i << ": " << K[i] << " " << Kk[i] << " " << Kg[i] << endl;
  
  for(int i=1;i<M;i++){
    if( i + i == M ) continue;    
    int mini = min( K[ i ] , K[M-i] );
    //cout << mini << endl;
    //cout << i << ": " << K[i] << " "<< Kk[i] << " " << Kg[i] << endl;
    res += mini;
    K[i] -= mini;
    K[M-i] -= mini;
    for(int j=0;j<mini;j++){
      del(i); del(M-i);
    }
  }
  for(int i=0;i<M;i++){
    //cout << i << ": " << K[i] << " "<< Kk[i] << " " << Kg[i] << endl;
    if( i == 0 || i + i == M ){
      res += K[i]/2;
    } else
      res += Kg[i];
  }
  cout << res << endl;
}

