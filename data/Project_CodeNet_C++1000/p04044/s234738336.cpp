#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,L;
  cin >> N >> L;
  
  string s;
  
  vector<string> v;
  for(int i=0; i<N; i++){
    cin >> s;
    v.push_back(s);
  }
  
  sort(v.begin(), v.end());
  for(int i=0; i<N; i++){
    cout << v.at(i);
  }
}
  
