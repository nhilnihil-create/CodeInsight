#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
  vector<int> data;
  int a,b,c;
  cin>>a>>b;
  for(int i=0;i<a;i++){
    cin>>c;
    data.push_back(c);
  }
  c=0;
  sort(data.begin(),data.end());
  a=data.size();
  for(int i=data.size()-1;i>a-b-1;i--){

    c+=data[i];
  }
  cout<<c<<endl;
}