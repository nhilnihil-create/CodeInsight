#include <bits/stdc++.h>

using namespace std;

int main(){
  long long h,w;
  cin >> h >> w;
  if(h%3==0 || w%3==0){
    cout << 0 << endl;
    return 0;
  }
  long long dx[2]={h/3,h/3+1};
  long long dy[2]={w/3,w/3+1};
  long long m=10000000000;
  for(long long i=1;i<w;i++){
    long long s1,s2,s3;
    long long p,q;
    s1=h*i;
    s2=(w-i)*(h/2);
    s3=h*w-s1-s2;
    p=max(s1,max(s2,s3));
    q=min(s1,min(s2,s3));
    m=min(m,p-q);
  }
  for(long long i=1;i<h;i++){
    long long s1,s2,s3;
    long long p,q;
    s1=w*i;
    s2=(h-i)*(w/2);
    s3=h*w-s1-s2;
    p=max(s1,max(s2,s3));
    q=min(s1,min(s2,s3));
    m=min(m,p-q);
  }
  m=min(m,min(h,w));
  cout << m << endl;
}
