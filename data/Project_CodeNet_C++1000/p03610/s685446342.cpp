# include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  vector <char> A;
  for (int i=0; i<s.length(); i+=2){
    A.push_back(s.at(i));
  }
  for (int i=0; i<A.size();i++){
    cout << A.at(i);
  }
}
