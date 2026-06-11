#include<bits/stdc++.h>
using namespace std;
int main(){
  int h,w;
  cin >> h >> w;
  int i,j;
  long minn = 999999999;
  long tmp = 0;
  if(h%3==0||w%3==0)cout << 0 << endl;
  else{
    for(i=max(1,w/3-100);i<=min(w-1,w/3+100);i++){
      for(j=max(1,h/2-100);j<=min(h-1,h/2+100);j++){
        tmp = max(h*i,max((w-i)*j,(w-i)*(h-j)))-min(h*i,min((w-i)*j,(w-i)*(h-j)));
        if(minn>tmp)minn = tmp;
      }
    }
    for(i=max(1,h/3-100);i<=min(h-1,h/3+100);i++){
      for(j=max(1,w/2-100);j<=min(w-1,w/2+100);j++){
        tmp = max(w*i,max((h-i)*j,(h-i)*(w-j)))-min(w*i,min((h-i)*j,(h-i)*(w-j)));
        if(minn>tmp)minn = tmp;
      }
    }
    if(min(w,h)<minn)minn=min(w,h);
    cout << minn << endl;
  }

}
