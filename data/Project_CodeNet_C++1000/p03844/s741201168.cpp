#include <bits/stdc++.h>
using namespace std;

int main() {
  int YABAI, WAYO;
  string TKSS, EKSA, LAPLAND;
  cin >> YABAI >> EKSA >> WAYO;
  
  if(EKSA == "+"){
    YABAI += WAYO;
  }
  else{
    YABAI -= WAYO;
  }
  
  cout << YABAI << endl;
  
}