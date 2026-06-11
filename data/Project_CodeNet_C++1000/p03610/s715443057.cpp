#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s;
  cin >> s;
  
  string t;
  for(int i = 0; i < static_cast<int>(s.size()); i++){
    if( (i % 2) == 0){
      t += s.at(i);
    }
  }
  
  cout << t << endl;
}