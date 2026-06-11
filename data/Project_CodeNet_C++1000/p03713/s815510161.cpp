#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int main()
{
  ll h,w,n,t,s,res;
  cin >> h >> w;
  n=h*w;
  if(h%3==0||w%3==0){
    res=0;
  }else{
    t=(h/3)*w;
    s=max(((h-h/3)/2)*w,(w/2)*(h-h/3));
    res=max({t,s,n-t-s})-min({t,s,n-t-s});
    t=(h/3+1)*w;
    s=max(((h-h/3-1)/2)*w,(w/2)*(h-h/3-1));
    res=min(res,max({t,s,n-t-s})-min({t,s,n-t-s}));
    t=(w/3)*h;
    s=max(((w-w/3)/2)*h,(h/2)*(w-w/3));
    res=min(res,max({t,s,n-t-s})-min({t,s,n-t-s}));
    t=(w/3+1)*h;
    s=max(((w-w/3-1)/2)*h,(h/2)*(w-w/3-1));
    res=min(res,max({t,s,n-t-s})-min({t,s,n-t-s}));
  }
  cout << res << endl;
  return 0;
}