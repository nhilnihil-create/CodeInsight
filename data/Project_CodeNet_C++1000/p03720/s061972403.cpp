#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main(void){
  int N, M;
  cin >> N >> M;
  vector<int> a(M*2);
  for(int i=0; i<M*2; i++) cin >> a[i];
  
  int j = 0;
  sort((a).begin(), (a).end());
  for(int i=1; i<=N; i++){
    int count = 0;
    while(a[j] == i){
      count++;
      j++;
    }//while
    cout << count << "\n";
  }//for
 
}
