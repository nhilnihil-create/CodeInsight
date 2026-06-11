#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  int i;
  for(i=0;i<n;i++){
    cin >> a.at(i);
  }
  int current = 1;
  int count = 0;
  vector<int> push(n);
  for(i=0;i<n;i++){
     current--;
    if(a.at(current) == 2){
      count++;
      break;
    }
    else if(push.at(current) == 1){
      count = -1;
      break;
    }
    else{
      push.at(current)++;
      count++;
      current = a.at(current);
    }
  }
  cout << count << endl;
}
