#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,count=1,num=0;
  cin >> N;
  vector<int> light(N);
  
    for (int i = 0; i < N; i++) {
    cin >> light.at(i);
    }
  int ON =0;
	for (int i = 0; i < N; i++) {
          ON =  light.at(ON);
  		  if (ON ==2){
            break;
   		 }if (ON !=2) {
    		 count ++;
    	 }
          ON = ON - 1;
 	  }
    if (ON ==2){
              cout << count << endl;}
    else {cout << "-1" << endl;  
         }
  }
