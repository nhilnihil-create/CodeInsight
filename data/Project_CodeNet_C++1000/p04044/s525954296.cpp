#include<bits/stdc++.h>
using namespace std;

int main(){
 int N,L;
  cin >> N >> L;
  vector<string> G(N);
  for(int i=0; i<N; i++){
   	cin >> G[i]; 
  }
  sort(G.begin(),G.end());
  for(int i=0; i<N; i++){
    cout << G[i]; 
  }
  cout << endl;
}