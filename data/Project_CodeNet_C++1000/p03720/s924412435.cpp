#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin>>n>>m;
  vector <int>a(m),b(m);
  for (int i=0;i<m;i++) cin>>a.at(i)>>b.at(i);
  for(int p=0;p<n;p++){
    int sum=0;
    for (int i=0;i<m;i++){
      if((a.at(i)==p+1)||(b.at(i)==p+1))
        sum++;
    }
    cout<<sum<<endl;
  }
}