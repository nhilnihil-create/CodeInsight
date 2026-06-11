#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
	int n,l;
  cin>>n>>l;
  vector<string>s(n);
  for(int i=0;i<n;i++){
	  cin>>s[i];
  }
  sort(s.begin(),s.end());
  for(int i=0;i<n;i++){
	  cout<<s[i];
  }
  
	return 0;
}
