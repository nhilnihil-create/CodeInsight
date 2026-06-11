#include<bits/stdc++.h>
using namespace std;

bool prime(int n){
  if(n%2==0) return false;
  for(int i=3;i<sqrt(n);i+=2){
    if(n%i==0) return false;
  }
  return true;
}

int focount(int h,int w){
  if(h<=1||w<=1) return 0;
  return h/2+w/2-1+focount(h-2,w-2);
}

int main(){
  int h,w;
  cin >> h >> w;
  char a;
  int count[26];
  int forcount,twocount,onecount;
  for(int i=0;i<26;i++) count[i]=0;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin >> a;
      count[a-97]++;
    }
  }
  
  forcount=focount(h,w);
  twocount=(h*w-4*forcount)/2;
  onecount=h*w-4*forcount-2*twocount;
  for(int i=0;i<26;i++){
    if(count[i]>=4){
      forcount-=count[i]/4;
      count[i]=count[i]%4;
      if(forcount<0) {
	count[i]-=4*forcount;
	forcount=0;
      }
    }
    if(forcount==0) break;
  }
  if(forcount!=0) {
    cout << "No" << endl;
    return 0;
  }
  for(int i=0;i<26;i++){
    if(count[i]>=2){
      twocount-=count[i]/2;
      count[i]=count[i]%2;
      if(twocount<0) {
	count[i]-=twocount;
	twocount=0;
      }
    }
    if(twocount==0) break;
  }
  if(twocount!=0) {
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
  return 0;
}
