#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
  int N;
  cin >> N;
  
  vector<int> rate(9, 0);
  int kind = 0;
  for (int i = 0; i < N; i++){
    int a;
    cin >> a;
    a /= 400;
    
    if (a < 8){
      if (rate.at(a) == 0){
        kind++;
      }
      
      rate.at(a)++;
    }
    else{
      rate.at(8)++;
    }
  }
  
  int kindmin, kindmax;
  kindmin = max(kind, 1);
  kindmax = kind + rate.at(8);
  
  cout << kindmin << ' ' << kindmax << endl;
}