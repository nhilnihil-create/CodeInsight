#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int A,B;
  cin >> A >> B;
  int C=A+B;
  for(int i=0;i<N;i++){
    char x;
    cin >> x;
    if(x=='a'&&C>0){
      cout << "Yes" << endl;
      C--;
    }else if(x=='b'&&B>0&&C>0){
      cout << "Yes" << endl;
      B--;
      C--;
    }else{
      cout << "No" << endl;
    }
  }
}
