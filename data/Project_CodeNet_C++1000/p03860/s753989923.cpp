    #include <bits/stdc++.h>
    using namespace std;
     
    int main() {
      string x, s, y, X, S, Y, connect;
      
      cin >> x >> s >> y;
      X = x.at(0);
      S = s.at(0);
      Y = y.at(0);
      connect = X + S + Y;
      
      cout << connect << endl;
    }