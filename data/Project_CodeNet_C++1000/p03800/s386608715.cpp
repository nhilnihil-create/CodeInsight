#include<bits/stdc++.h>
using namespace std;
bool search();
int ans[100009];
int n;
string s;

int main(){
  cin>>n>>s;
  for(int i=0;i<2;i++){
    for(int j=0;j<2;j++){
      memset(ans,0,sizeof(ans));
      ans[0]=i;
      ans[1]=j;

      if(search()){
	for(int k=0;k<n;k++){
	  if(ans[k]==0){
	    cout<<'S';
	  }
	  else{
	    cout<<'W';
	  }
	}
	cout<<endl;
	return(0);
      }
    }
  }

  cout<<-1<<endl;
  return(0);
}

bool search(){
  for(int i=2;i<n;i++){
    if(ans[i-1]==0){
      if(s[i-1]=='o'){
	ans[i]=ans[i-2];
      }
      else{
	ans[i]=!ans[i-2];
      }
    }
    else{
      if(s[i-1]=='o'){
	ans[i]=!ans[i-2];
      }
      else{
	ans[i]=ans[i-2];
      }
    }
  }

  int cnt=0;
  if(ans[0]==0){
    if(s[0]=='o'&&ans[n-1]==ans[1])cnt++;
    else if(s[0]=='x'&&ans[n-1]!=ans[1])cnt++;
  }
  else{
    if(s[0]=='o'&&ans[n-1]!=ans[1])cnt++;
    else if(s[0]=='x'&&ans[n-1]==ans[1])cnt++;
  }
  if(ans[n-1]==0){
    if(s[n-1]=='o'&&ans[n-2]==ans[0])cnt++;
    else if(s[n-1]=='x'&&ans[n-2]!=ans[0])cnt++;
  }
  else{
    if(s[n-1]=='o'&&ans[n-2]!=ans[0])cnt++;
    else if(s[n-1]=='x'&&ans[n-2]==ans[0])cnt++;
  }

  if(cnt==2)return true;
  else return false;
}
