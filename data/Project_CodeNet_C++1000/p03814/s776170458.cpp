 #include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int count = 0;
  for(int i = 0; s.at(i) != 'A';++i){
    count++;
  }
  int zcount = s.size();
 for(int i = s.size()-1; s.at(i) != 'Z'; --i){
   zcount--;
 }
  
  cout << zcount - count<< endl;
}

