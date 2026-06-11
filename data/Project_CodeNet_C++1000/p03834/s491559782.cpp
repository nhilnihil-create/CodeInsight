#include <bits/stdc++.h>
using namespace std;

int main() {

  string s;

  cin >> s;
  int len = s.length();
for(int i = 0;i < len ;i++){
    if(s.at(i) == ','){
        i++;
        cout << " ";
    }
    cout << s.at(i);
}



}

   