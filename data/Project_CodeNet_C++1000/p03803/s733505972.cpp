#include <bits/stdc++.h>
using namespace std;

int main() {
  int aliceCard,bobCard;
  
  cin >> aliceCard >> bobCard;
  
  if(aliceCard == 1) aliceCard += 13;
  if(bobCard == 1) bobCard += 13;
  
  if(aliceCard > bobCard) cout << "Alice";
  else if(aliceCard < bobCard) cout << "Bob";
  else cout << "Draw";
}
