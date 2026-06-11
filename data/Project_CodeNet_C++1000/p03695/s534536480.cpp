#include <bits/stdc++.h>
using namespace std;
int n,i,j,a,b,c,m,M,r;
int main(){
  cin>>n;
  vector<int> col(8,0);
  for(;i<n;i++){
    cin>>r;
    if(r<400)col[0]++;
    else if(r<800)col[1]++;
    else if(r<1200)col[2]++;
    else if(r<1600)col[3]++;
    else if(r<2000)col[4]++;
    else if(r<2400)col[5]++;
    else if(r<2800)col[6]++;
    else if(r<3200)col[7]++;
    else c++;
  }
  for(i=0;i<8;i++)if(col[i]!=0)m++;
  if(m==0)m=1,M=c;
  else M=m+c;
  cout<<m<<" "<<M;
}