#include<bits/stdc++.h>
using namespace std;
int main(){
	int h,w;cin>>h>>w;
  vector<vector<char > >mat(h,vector<char >(w,'.'));
  for(int i=0;i<h;i++)
    for(int j=0;j<w;j++)cin>>mat[i][j];
  for(int i=0;i<h;i++){
  if(i==0){for(int l=0;l<w+2;l++)cout<<'#';cout<<'\n';}
  cout<<'#';
  	for(int j=0;j<w;j++)
    cout<<mat[i][j];
  cout<<"#\n";
  if(i==h-1){for(int l=0;l<w+2;l++)cout<<'#';cout<<'\n';}

  }
}