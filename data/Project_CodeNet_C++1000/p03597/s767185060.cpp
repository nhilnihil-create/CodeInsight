#include <bits/stdc++.h>
using namespace std;
 
int main() {

int N, A, B;

cin >> N >> A;

if(N * N < A){
  cout << "error" << endl;
}
else{
  B = N * N - A;

  cout << B << endl;
}

}
