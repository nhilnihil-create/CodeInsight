#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
  long long N, C, K;
  cin >> N >> C >> K;
 
  vector<long long> t(N);
  for(int i=0; i<N; i++) cin >> t[i];
  sort(t.begin(), t.end());
  
  int start = t[0];
  int bus = 0;
  int customer = 1;
  for(int i=1; i<N; i++){
     if(t[i] - start > K || customer == C){
  		//cout << t[i] << "\n";
		start = t[i];
        customer = 1;
		bus++;
     }else{
		customer++;
     }
	
  }//for
  if(customer > 0) bus++;
     cout << bus << "\n";
}//main
