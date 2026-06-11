#include<iostream>
using namespace std;
#define df 0
typedef long int li;
#include<algorithm> // sort,reverse,min,lower_bound

li f(int a,int b,int k);
  
int main(){
  if(df) printf("*debug mode*\n");
  int n,a,b; cin >>n >>a >>b;
  li v[n];
  for(li& x: v) cin >>x;
  sort(v,v+n,less<li>());
  if(df){
    for(li x: v) printf("%ld ",x);
    printf("\n");
  }
  li sum=0;int flag=1;
  for(int i=n-1;i>=n-a;i--){
    sum+=v[i];
    if(v[i]!=v[n-1])flag=0;
  }
  printf("%.10lf\n",sum/(double)a);
  if(flag){
    int k=(v+n)-lower_bound(v,v+n,v[n-1]);
    printf("%ld\n",f(a,b,k));
  }else{
    li* l=lower_bound(v,v+n,v[n-a]);
    li* u=upper_bound(v,v+n,v[n-a]);
    if(df) printf("%d::a:%d(%d) k:%d\n",v[n-a],a-((v+n)-u),(v+n)-u,u-l);
    printf("%ld\n",f(a-((v+n)-u),a-((v+n)-u),u-l));
  }
}

li f(int a,int b,int k){
  li temp=1;
  for(int i=0;i<a;i++){
    (temp*=k-i)/=i+1;
  }
  li sum=temp;
  for(int i=a;i<b;i++){
    (temp*=k-i)/=i+1;
    sum+=temp;
  }
  return sum;
}

/// confirm df==0 ///
