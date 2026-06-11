#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,k;
  cin >> n >> k;
  vector<int> vec(n);
  for(int i = 0;i < n;i ++)cin >> vec.at(i);
  
  int count = 0;
  for(int i = 0;i < n;i ++){
    count += min(vec.at(i),k - vec.at(i)) * 2;
  }
  
  cout << count << endl;
}