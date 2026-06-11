#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<char>a(10);
  for(int i=0;i<10;i++)
    cin >> a.at(i);
  vector<char>b(0);
  for(int i=0;i<10;i++){
    if(a.at(i)=='1')
      b.push_back('1');
    if(a.at(i)=='0')
      b.push_back('0');
    if(a.at(i)=='B'){
      if(b.size()>0)
        b.pop_back();
    }
  }
  for(int i=0;i<b.size();i++)
    cout << b.at(i);
  cout << endl;
}