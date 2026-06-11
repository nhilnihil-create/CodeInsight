#include<bits/stdc++.h>
#include<math.h>
using namespace std;


int main(){
  int N;
  cin >> N;
  int tmp, parity=0;
  for (int i=0;i<N;i++){
    cin >> tmp;
    parity += tmp%2;
  }
  cout << (parity%2? "NO" : "YES") << endl;
}
 