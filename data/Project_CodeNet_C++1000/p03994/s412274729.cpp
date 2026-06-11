#include<bits/stdc++.h>
using namespace std;

int main(){
  string S;
  int K;
  cin >> S >> K;
  int N=S.size();
  vector<int> sa(N);
  for(int i=0; i<N; i++){
    sa[i]=('z'-S[i]+1)%26;
  }
  for(int i=0; i<N; i++){
    if(sa[i]<=K){
      K-=sa[i];
      S[i]='a';
    }
  }
  S[N-1]=(S[N-1]-'a'+K)%26+'a';
  cout << S << endl;
  return 0;
}