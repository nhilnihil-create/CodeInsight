#include <bits/stdc++.h>
using namespace std;

int main() {
				    // *constraint*
  int N,K;    	    // 1<=N<=100 N is the number of balls 
  					// 1<=K<=100 K is the x-coordinate of robot 
  					// 0 < xi < K
  				    // Enter an Integer
  
  int distance = 0;
  cin  >> N >> K;
  int x;
  int i = 1;
  while (i <= N) {
    cin >> x;
    if( x < K - x){
      distance += x * 2;
    }else{
      distance += (K-x) * 2;
    }
    i++;
  }
  cout << distance << endl;
}
