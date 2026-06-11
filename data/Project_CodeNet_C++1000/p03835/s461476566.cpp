#include <bits/stdc++.h>
using namespace std;

int main() {
  int K,S;
  int num=0;
  cin >> K >> S;
  for(int x=0;x<=K;x++){
    for(int y=0;y<=K;y++){
      if(S-x-y>=0&&K>=S-x-y) num++;
    }
  }
  cout << num;
}
