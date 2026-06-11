#include <bits/stdc++.h>
using namespace std;

int main() {
  long H,W;
  cin>>H>>W;

  long ans=1234567890;
  for(long i=0;i<H;i++){
    long h1= i;
    long h2 = (H-i)/2;
    long h3 = H-h1-h2;
    long s1 = h1*W;
    long s2 = h2*W;
    long s3 = h3*W;
    long m=min(s1,min(s2,s3));
    long M=max(s1,max(s2,s3));
    ans = min(ans,M-m);
  }

  for(long i=0;i<W;i++){
    long w1= i;
    long w2 = (H-i)/2;
    long w3 = H-w1-w2;
    long s1 = w1*H;
    long s2 = w2*H;
    long s3 = w3*H;
    long m=min(s1,min(s2,s3));
    long M=max(s1,max(s2,s3));
    ans = min(ans,M-m);
  }

  for(long i=0;i<H;i++){
    long h1= i;
    long h2=H-i;
    long h3=H-i;
    long w1=W;
    long w2= W/2;
    long w3= W-w2;
    long s1=h1*w1;
    long s2=h2*w2;
    long s3=h3*w3;
    long m=min(s1,min(s2,s3));
    long M=max(s1,max(s2,s3));
    ans = min(ans,M-m);
  }

  for(long i=0;i<W;i++){
    long w1= i;
    long w2=W-i;
    long w3=W-i;
    long h1=H;
    long h2= H/2;
    long h3= H-h2;
    long s1=h1*w1;
    long s2=h2*w2;
    long s3=h3*w3;
    long m=min(s1,min(s2,s3));
    long M=max(s1,max(s2,s3));
    ans = min(ans,M-m);
  }

  cout<<ans<<endl;

}
