#include<bits/stdc++.h>
using namespace std;

int calc(int a, int b, int c, int d){
  int e = min(a,c);
  a -= e;
  c -= e;
  b *= 2;
  d *= 2;
  if(a != 0){
    int x = min(a,d);
    e += x;
    a -= x;
    d -= x;
  }
  else if(c != 0){
    int x = min(c,b);
    e += x;
    c -= x;
    b -= x;
  }
  e += b/2;
  e += d/2;
  return e;
}
    

int main(){
  int N, M;
  cin >> N >> M;
  vector<int> vec(N);
  for(int i=0; i<N; i++){
    cin >> vec.at(i);
  }
  vector<map<int,int>> P(M);
  vector<int> ones(M);
  vector<int> pairs(M);
  for(int i=0; i<N; i++){
    int x = vec.at(i) %M;
    if(P.at(x).count(vec.at(i))){
      P.at(x)[vec.at(i)]++;
    }
    else{
      P.at(x)[vec.at(i)] = 1;
    }
    if(P.at(x)[vec.at(i)] %2 == 0){
      pairs.at(x)++;
      ones.at(x)--;
    }
    else{
      ones.at(x)++;
    }
  }
  
  int ans = 0;
  
  for(int i=0; i<M; i++){
    int a = i;
    int b = (M - i)%M;
    if(a == b){
      ans += (ones.at(a) + pairs.at(a)*2)/2;
    }
    else if(a < b){
      ans += calc(ones.at(a), pairs.at(a), ones.at(b), pairs.at(b));
    }
  }
  cout << ans << endl;
}  