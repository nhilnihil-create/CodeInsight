#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(){
  int A,B;
  cin >> A >> B;
  if(A%3 == 0) cout << "Possible" << endl;
  else if(B%3 == 0) cout << "Possible" << endl;
  else if((A + B)%3 == 0) cout << "Possible" << endl;
  else cout << "Impossible" << endl;
}
