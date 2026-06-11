#include<bits/stdc++.h>
using namespace std;
#define int long long 

signed main(void){ 
 
  int N; cin >> N;
  int check = 0;
  vector<int> A(N);
  vector<int> vec;
  map<int,int> mp;
 
  int sum = 0;
  
  for(int i = 0; i < N; i++){ 
    cin >> A[i]; mp[A[i]]++; sum += A[i];
    if( check < A[i] ){ vec.push_back(i); check = A[i]; }
  }
  
  int m = vec.size(); 
  
  vector<int> ans(N,0);

  
  for(int i = m-1; i > 0; i--){
    int res = 0;
    while( mp.rbegin()->first > A[vec[i-1]] ){ 
      
      int a = mp.rbegin()->first;
      int b = mp.rbegin()->second;
      
      res += (a-A[vec[i-1]])*b;
      
      mp[A[vec[i-1]]] += b;
      
      mp.erase(a);
      
    }
    
    ans[vec[i]] = res;
    
    sum -= res;
        
    
  }
  
  ans[0] = sum;
  
  for(int i = 0; i < N; i++){
    cout << ans[i] << endl;
  }
  
  return 0;
}
  