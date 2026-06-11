#include <iostream>
#include <vector>
using namespace std;


int main(void){
  int N;
  cin >> N;
  
  vector<long long> a(N); 
  int even = 0;
  int odd  = 0;
  for(long long i=0; i<N; i++){
      cin >> a[i];
      if(a[i]%2 == 0) even++; 
      else odd++;
  }//for

  if(odd%2 == 0) cout << "YES" << "\n";
  else  cout << "NO" << "\n";

}//main
