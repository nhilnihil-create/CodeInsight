#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(){
  int n,l;
  cin>>n>>l;
  string a;
  vector<string> list;
  for(int i=0;i<n;i++)
  {
    cin>>a;
    list.push_back(a);
  }
  sort(list.begin(),list.end());
  for(int i=0;i<n;i++)
  {
    cout<<list.at(i);
  }
  cout<<endl;
}