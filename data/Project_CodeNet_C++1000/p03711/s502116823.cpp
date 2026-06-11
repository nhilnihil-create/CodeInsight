#include <bits/stdc++.h>
using namespace std;

int main() {
	int x,y;
	cin >> x >> y;
    int ans = 0;
    vector<int>vec = {1,3,5,7,8,10,12};
    vector<int>usi = {4,6,9,11};
    for(int i = 0; i < 7; i++){
      for(int j = 0; j < 7; j++){
      if(x == vec[i] && y == vec[j]){
        ans++;
      }
      }
    }
    for(int i = 0; i < 4; i++){
      for(int j = 0; j < 4; j++){
      if(x == usi[i] && y == usi[j]){
        ans++;
      }
      }
    }
   if(x == 2 || y == 2){
     cout << "No" << endl;
   }
   else if(x == y){
     cout << "Yes" <<endl;
   }
   else if(ans >= 1){
     cout << "Yes" <<endl;
   }
   else{
     cout << "No" << endl;
   }
}

