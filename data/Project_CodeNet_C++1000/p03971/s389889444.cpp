#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,a,b;
  cin >> n >> a >> b;
  vector<char> vec(n);
  int ab = a + b;
  
  for(int i = 0;i < n;i ++){
    cin >> vec.at(i);
    if(vec.at(i) == 'a' && ab > 0){ab --;cout << "Yes" << endl;}
    else if(vec.at(i) == 'b' && ab > 0 && b > 0){ab --;b --;cout << "Yes" << endl;}
    else cout << "No" << endl;
  }
}