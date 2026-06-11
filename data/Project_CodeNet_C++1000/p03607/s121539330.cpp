#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const long long MAX=1e9 + 5;


int main(void){
  int N;
  cin >> N;
  
  vector<long long> a(N);
  for(int i=0; i<N; i++) cin >> a[i];
  sort(a.begin(), a.end()); 

  int count = 0;
  for(int i=0; i<N; i++){
     int k = i;
     int odd = 1;
     while(a[k] == a[k+1]){
	odd++;
	k++;
      	i=k;
     }//while
     if(odd%2 ==1) count++;
  }//for

  cout << count << "\n";
}//main
