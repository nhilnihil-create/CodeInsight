#include<bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;
  int min=0;

  map<int,int> num;


  for(int i =0; i < S.size(); i++){
    if( num.count((int)S.at(i) - 97) > 0)
      num.at((int)S.at(i) - 97)++;
    else
      num[(int)S.at(i) - 97]=1;
  }

  for(int i=0;i<26;i++){
    if(num.count(i) == 0)
      break;
    else
      min++;
  }

  if(min==26)
    cout << "None" << endl;
  else
    cout << (char)(min+97) << endl;

}
