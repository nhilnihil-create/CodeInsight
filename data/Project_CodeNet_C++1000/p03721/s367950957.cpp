#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  int64_t k;
  cin>>n>>k;
  vector<vector<int>> ab(n,vector<int>(2));
  for(int i=0;i<n;i++)
    cin>>ab.at(i).at(0)>>ab.at(i).at(1);
  sort(ab.begin(),ab.end());
  int64_t c=0;
  for(int i=0;i<n;i++){
    c+=ab.at(i).at(1);
    if(c>=k){
      cout<<ab.at(i).at(0)<<endl;
      break;
    }
  }
}