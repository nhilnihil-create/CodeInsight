#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  int K;
  cin >> S >> K;

  for(int i=0;i<S.size();i++){
    if(S.at(i)=='a')  continue;
    int tmp=26-(S.at(i)-'a');
    if(tmp<=K){
      S.at(i)='a';
      K-=tmp;
    }
  }
  S.at(S.size()-1)=((S.at(S.size()-1)-'a')+K%26)%26+'a';
  cout << S << endl;

  return 0;
}