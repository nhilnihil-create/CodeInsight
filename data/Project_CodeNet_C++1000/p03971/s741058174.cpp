#include <bits/stdc++.h>
#include<iostream>
using namespace std;
 
int main() {
  int n , a, b,ac(0),bc(0);

  cin >> n >> a >> b;
  vector<char> c(n);

  for(int i = 0;i < n ; i++){
      cin >> c.at(i);
  }

  for(int i = 0; i < n ;i++){

    if(c.at(i) == 'a'){
        if(ac < (a+b)){
            cout << "Yes" << endl;
            ac++;
        }else{
            cout << "No" << endl;
        }
    }

    if(c.at(i) == 'b'){
        if(ac < (a+b) && bc < b){
            cout << "Yes" << endl;
            ac++;
            bc++;
        }else{
            cout << "No" << endl;
        }
    }
    

    if(c.at(i) == 'c'){
          cout << "No" << endl;
      }
    }
  
}
   