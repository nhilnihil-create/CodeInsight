#include <bits/stdc++.h>
using namespace std;

int main() {
  int x, y;
  cin >> x >> y;

  vector<int> A={1,3,5,7,8,10,12};
  vector<int> B={4,6,9,11};
  
  if(x==2 || y==2){
    cout << "No" <<endl;
    return 0;
  }

  if(count(A.begin(), A.end(), x)==count(A.begin(), A.end(), y)){
    cout << "Yes" << endl;
  }
  else if(count(B.begin(), B.end(), x)==count(B.begin(), B.end(), y)){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
return 0;  
}