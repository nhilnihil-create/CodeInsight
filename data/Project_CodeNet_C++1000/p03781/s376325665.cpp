#include "bits/stdc++.h"
#define rep(i,a,n) for(int i = (a);i < (n);i++)
using namespace std;

int main(){
  	int n,memo = 0;
  
  	cin >> n;
  	
  	for(int i = 1;;i++){
      memo += i;
      if(memo >= n){
        cout << i << endl;
        return 0;
      }
    }
 	return 0; 
}