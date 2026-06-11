#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
	int a[3];
  int x=0,y=0;
  cin>>a[0]>>a[1]>>a[2];
  for(int i=0;i<3;i++){
    if(a[i]==5)
      x++;
    else if(a[i]==7)
      y++;
  }
  if(x==2 && y==1){
    cout<<"YES\n";
  }
else{
  cout<<"NO\n";
}
	return 0;
}
