#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
  cin >> N;
  vector<int>a(N);
  cin >> a.at(0);
  //int done=0;
  for(int i = 1 ; i < N ; i++){
  	cin >> a.at(i);
    //done += (a.at(i) - a.at(0));
  }
  
  /*if(done == 0){
  	cout << 0 << endl;
    return 0;
  }*/
  
  int min = 1000000;
  int cal = 0;
  
  for(int i = -100 ; i <= 100 ; i++){
  	int y = i;
      for(int j = 0 ; j < N ; j++){
  	 		cal += (y - a.at(j))*(y - a.at(j));
  	  }
    
    if(min > cal)min = cal;
    cal = 0;
  }
  cout << min << endl;
}
