 #include<bits/stdc++.h>
using namespace std;
int main(){
  int n,l;
  cin>>n>>l;
  vector<string>v(n);
  for(int i=0;i<n;i++){
    cin>>v[i];
    }
  sort(v.begin(),v.end());
  string t = "";
  for(int i=0;i<n;i++){
    t+=v[i];
    }
  cout<<t<<endl;
  }
