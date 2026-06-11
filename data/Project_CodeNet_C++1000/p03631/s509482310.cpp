#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;

int main(){
  string x,y;
  cin >> x;
  y = x;
  reverse(x.begin(), x.end());
  if(x == y){
    cout << "Yes" << endl;
  } else { 
    cout << "No" << endl;
  }
}


