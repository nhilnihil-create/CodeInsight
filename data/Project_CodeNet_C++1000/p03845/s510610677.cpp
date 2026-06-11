#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  cin >>n;int sum=0;
    vector<int> vec(n);
  
for (int i = 0; i < n; i++) {
        cin>> vec.at(i);
      sum+=vec[i];
    }
  int m;
  cin >>m;
  vector<int> memo(2);
  int i=0;
while(i<m){
cin >> memo[0] >>memo[1];
int k= vec[memo[0]-1]-memo[1];
  cout << sum - k <<endl;
i++;
  
}
   
  
}