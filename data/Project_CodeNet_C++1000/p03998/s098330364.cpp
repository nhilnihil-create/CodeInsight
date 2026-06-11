#include <bits/stdc++.h>
using namespace std;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep2(i,m,n) for(int (i)=(m);(i)<(n);(i)++)
#define ll long long
#define ld long double
#define all(a) (a).begin(),(a).end()
#define mk make_pair
int main(){
  string sa,sb,sc;
  cin>>sa>>sb>>sc;
  int n=sa.size(); int m=sb.size(); int l=sc.size();
  char turn='a';
  int ca=0; int cb=0; int cc=0;
  rep(i,n+m+l+1){
    if(turn=='a'){
      if(sa[ca]=='a') turn='a';
else  if(sa[ca]=='b') turn='b';
else  if(sa[ca]=='c') turn='c';
      ca++;
    }
    if(turn=='b'){
      if(sb[cb]=='a') turn='a';
else  if(sb[cb]=='b') turn='b';
else  if(sb[cb]=='c') turn='c';
      cb++;
    }
    if(turn=='c'){
      if(sc[cc]=='a') turn='a';
else  if(sc[cc]=='b') turn='b';
else  if(sc[cc]=='c') turn='c';
      cc++;
    }
  if(ca==n+1){
    cout<<'A';
    return 0;
  }
else if(cb==m+1){
    cout<<'B';
    return 0;
  }
   if(cc==l+1){
    cout<<'C';
    return 0;
  } 
  }
    return 0;
}