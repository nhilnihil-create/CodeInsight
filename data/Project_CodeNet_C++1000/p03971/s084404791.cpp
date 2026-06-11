#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,a,b;
  cin >> n >> a >> b;
  string s;
  cin >> s;
  int count=0;
  int count_b=0;
  for(int i=0;i<n;i++){
    if(s.at(i) == 'a' && count < a+b){
      count++;
      cout << "Yes" <<endl;
    }
    else if (s.at(i) == 'b' && count < a+b && count_b < b){
      count++;
      count_b++;
      cout << "Yes" << endl;
    }
    else
      cout << "No" << endl;
  }      
}
