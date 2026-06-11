#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin>>s;
  int n=s.size();
  vector<char>vec;
  
  for(int i=0;i<n;i++){
    if(i%2==0){
      vec.push_back(s[i]);
    }
  }
  for(int i=0;i<vec.size();i++){
    cout<<vec[i];
  }
  cout<<endl;
}
