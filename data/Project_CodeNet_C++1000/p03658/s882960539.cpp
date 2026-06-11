#include<bits/stdc++.h>
using namespace std;


int main(){

  int N,K,tmp,sum;
  cin >> N >> K;
  vector<int> l;
  for(int i=0; i<N; i++){
    cin >> tmp;
    l.push_back(tmp);
  }

  sort(l.begin(),l.end());
  reverse(l.begin(),l.end());

  sum=0;
  for(int i=0; i<K; i++){
    sum += l.at(i);
  }

  cout << sum << endl;


}
