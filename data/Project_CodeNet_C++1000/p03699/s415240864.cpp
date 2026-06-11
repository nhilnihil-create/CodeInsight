#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  int sum=0;
  for(int i=0;i<n;i++){
    cin >> a.at(i);
    sum = sum+a.at(i);
  }
  int c=0;
  if((sum%10)==0){
    sort(a.begin(), a.end());
    for(int i=0;i<n;i++){
      if((sum-a.at(i))%10!=0){
        sum=sum-a.at(i);
        break;
      }
      else if(i==n-1)
        sum=0;
    }
  }
    cout << sum << endl;
  
}

