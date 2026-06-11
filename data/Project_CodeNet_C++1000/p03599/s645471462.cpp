#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  
  int a,b,c,d,e,f;
  cin>>a>>b>>c>>d>>e>>f;
  set<int> water,sugar;
  int tmp=0,i=0,j=0;
  int imax=f/(100*a)+1,jmax=f/(100*b)+1;
  for(int i=0;i<=imax;i++){
    for(int j=0;j<=jmax;j++){
      tmp=100*a*i+100*b*j;
      if(tmp<=f)water.insert(tmp);
    }
  }
  tmp=0,i=0,j=0;
  imax=f/c+1,jmax=f/d+1;
  for(int i=0;i<=imax;i++){
    for(int j=0;j<=jmax;j++){
      tmp=c*i+d*j;
      if(tmp<=f)sugar.insert(tmp);
    }
  }
  
  double max_conc=0;
  int ans_sw=0,ans_s=0;
  for(auto w=water.begin();w!=water.end();++w){
    for(auto s=sugar.begin();s!=sugar.end();++s){
      if(*s+*w>f)continue;
      int max_sugar=*w/100*e;
      if(*s>max_sugar)continue;
      
      double conc;
      if((*s)+(*w)==0)conc=0;
      else conc=(double)(100*(*s)/(double)((*s)+(*w)));
      if(max_conc<=conc){
        max_conc=conc;
        ans_sw=*s+(*w);
        ans_s=*s;
      }
    }
  }
  cout<<ans_sw<<" "<<ans_s<<endl;
  
}