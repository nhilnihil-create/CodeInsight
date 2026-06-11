#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++){
    cin >> a.at(i);
  }
  deque<int> b;
  for(int i = 0; i < n; i++){
    if(i%2 == 0)b.push_back(a.at(i));
    else b.push_front(a.at(i));
  }
  if(n%2 == 1){
    reverse(b.begin(),b.end());
  }
  int size = b.size();
  for(int i = 0; i < size - 1; i++){
    cout << b.at(i) << " ";
  }
  cout << b.at(size-1) << endl;
}