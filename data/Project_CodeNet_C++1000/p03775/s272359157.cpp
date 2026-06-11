#include<iostream>
#include<algorithm>
#include<vector>
#include <iomanip>
#include <cmath>
#include <string.h>
#include <stdio.h>

using namespace std;

int findDigits(long long n){
	int digits = 0;
	while(n>0){
  	  digits++;
      n = n/10;
    }
  	return digits;
}

int main(){

  long long N;
  cin >> N;

  long long minF = 100000;
  for(long long i=1; i*i<=N ; i++){
  	if(N%i!=0)
      continue;
    long long B = N/i;
    long long F = max(findDigits(i), findDigits(B));
    minF = min(minF, F);
  }
 
  cout << minF << endl;

  return 0;
  
}
