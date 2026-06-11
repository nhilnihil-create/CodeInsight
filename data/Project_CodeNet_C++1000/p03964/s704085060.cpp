#include<bits/stdc++.h>
using namespace std;

int main(){
  int64_t n;
  cin >> n;
  vector<int64_t> t(n),a(n);
  for(int i = 0; i < n; i++){
    cin >> t.at(i) >> a.at(i);
  }

  int64_t ansa = a.at(0) , anst = t.at(0);
  for(int i = 1; i < n; i++){
    ansa = max((ansa-1)/a.at(i)+1,(anst-1)/t.at(i)+1)*a.at(i);
    anst = max((ansa-1)/a.at(i)+1,(anst-1)/t.at(i)+1)*t.at(i);    
  }
  cout << ansa+anst << endl;
  return 0;
}