#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  
  int size = s.size();
  int an = 0;
  int zn = 0;
  
  for(int i = 0;i < size;i ++){
    if(s[i] == 'A'){an = i;break;}
  }
  
  reverse(s.begin(),s.end());
  
  for(int i = 0;i < size;i ++){
    if(s[i] == 'Z'){zn = size - 1 - i;break;}
  }
  
  cout << zn - an + 1 << endl;
}