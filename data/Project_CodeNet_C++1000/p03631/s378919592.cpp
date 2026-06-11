#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  
  if (N%10*100 + N/10%10*10 + N/100 == N){
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}