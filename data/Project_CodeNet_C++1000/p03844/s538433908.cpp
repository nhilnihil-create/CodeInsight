    #include <bits/stdc++.h>
    using namespace std;
     
    int main() {
      int x, y, sum;
      string op;
      cin >> x >> op >> y;
      if (op == "+"){
        sum = x + y; 
      } else if(op == "-"){
        sum = x - y;
      } 
      cout << sum << endl;
    }