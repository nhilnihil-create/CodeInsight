#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W ;
  string str="#";
  vector< string > vec(W*H);

    for (int i = 0; i < (W+2);i++){
       cout << str ;
         }
    cout << endl;
  
    for (int ii = 0;ii < H; ii++){
  		cout << str;
  		for (int i = 0; i < 1; i++) {
    		cin >> vec.at(i);
            cout << vec.at(i);
    		}
        cout << str << endl;
           }
  
   for (int i = 0; i < (W+2);i++){
    cout << str;
          }
    cout << endl;
}
