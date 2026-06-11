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
  int n;
  cin>>n;
  vector<int> a(n);
 rep(i,n) cin>>a[i];
 vector<int> color(9);
 rep(i,n){
     if(a[i]<=399) color[0]++;
else if(a[i]<=799) color[1]++;
else if(a[i]<=1199) color[2]++;
else if(a[i]<=1599) color[3]++;
else if(a[i]<=1999) color[4]++;
else if(a[i]<=2399) color[5]++;
else if(a[i]<=2799) color[6]++;
else if(a[i]<=3199) color[7]++;
else  color[8]++;
 }
  int ans1=0;
  int ans2=0;
rep(i,8){
  if(color[i]!=0){
    ans1++;
    ans2++;
  }
}
cout<<max(ans2,1)<<" "<<ans1+color[8];
return 0;
}