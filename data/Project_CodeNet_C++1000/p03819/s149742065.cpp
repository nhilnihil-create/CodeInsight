#include<cmath>
#include<vector>
#include<iostream>
using namespace std;
#define df 0
int divup(int a,int b){return (a+b-1)/b;}
int pow(int a){return a*a;}

void add(int l,int r,vector<int>& imos){
  // [l,r]
  if(df)printf("add %d %d\n",l,r);
  imos.at(l)++;
  imos.at(r+1)--;
}
void add(int a,vector<int>& imos){
  // [a,a]
  if(df)printf("add %d\n",a);
  imos.at(a)++;
  imos.at(a+1)--;
}


void f(int l,int r,vector<int>& imos){
  int len=r-l+1;
  add(1,len,imos);
  int q0=divup(l,len+1);
  add(max(len+1,divup(l,q0)),r/q0,imos);
  for(int q=q0-1;q>0;q--){
    add(divup(l,q),r/q,imos);
  }
}

void g(int l,int r,vector<int>& imos){
  int len=r-l+1;
  for(int q=1;q<len;q++){
    add(divup(l,q),r/q,imos);
    add(q,imos);
  }
  if(df)printf("sq:%d\n",(int)(sqrt(l-0.5)));
  for(int q=len,sq=sqrt(l-0.5); q<=sq;q++){
    if(divup(l,q)==r/q){
      add(r/q,imos);
      add(q,imos);
    }
  }
  if(df)printf("sq:%d\n",(int)(sqrt(r+0.5)));
  if(l<=(pow((int)(sqrt(r+0.5))))){
    add((int)(sqrt(r+0.5)),imos);
  }
}

int main(){
  if(df) printf("*debug mode*\n");
  int n,m; cin >>n >>m;
  vector<int> imos(m+2,0);
  for(int i=0;i<n;i++){
    int l,r; cin >>l >>r;
    long int len=r-l+1;
    if(len*len>r) f(l,r,imos);
    else g(l,r,imos);
  }
  int sum=0;
  for(int i=1;i<=m;i++){
    sum+=imos.at(i);
    printf("%d\n",sum);
  }
}

/// confirm df==0 ///
