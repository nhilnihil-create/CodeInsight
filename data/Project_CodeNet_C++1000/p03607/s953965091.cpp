#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define rep1(i,n) for(int i=1; i<n; i++)

int main(){
  int N,count;
  cin >> N;
  count = 1;
  vector<int> vec(N);
  
  rep(i,N){
    cin >> vec[i];
  }
  
  sort(vec.begin(), vec.end());
  
  rep(i,N-1){
    if(vec[i] != vec[i+1]) count++;
    else {
      int j =i+1;
      int c = 0;
      while(vec[i] == vec[j]){
        c++;
        j++;
      }
      if(c%2 == 1) count--;
      i = j-2;
    }
  }
  
  cout << count << endl;
}