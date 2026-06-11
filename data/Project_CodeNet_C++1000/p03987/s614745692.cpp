#include<set> 
#include<map> 
#include<vector>
#include<algorithm> // sort,reverse,min,lower_bound

#include<iostream>
using namespace std;
#define df 0
#define rep(i,n) for(int i=0;i<(n);i++)
#define repa(i,a,n) for(int i=a;i<(n);i++)
typedef long int li;
// print_item
template<typename T>
void print_item(T x) {cout << x;}
// pair 型の print (map 含む)
template<typename F,typename S>
void print_item(pair<F,S> x);

// 汎用
void print(auto& vec,string str="");

int main(){
  if(df) printf("*debug mode*\n");
  int n; cin >>n;
  vector<li> vec(1,0),inv(n+1);
  rep(i,n){
    int a; cin >>a;
    vec.push_back(a);
    inv.at(a)=i+1;
  }
  vec.push_back(0);
  vector<li> lft(n+2,0),rgt(n+2,0);
  vector<int> lchain(n+2),rchain(n+2);
  rep(i,n+2){
    lchain.at(i)=i-1;
    rchain.at(i)=i+1;
  }
  for(int i=n;i>=1;i--){
    int j=inv.at(i); if(df)printf("%d(%d)\n",i,j);
    lft.at(j)=j-lchain.at(j);
    rgt.at(j)=rchain.at(j)-j;
    lchain.at(rchain.at(j))=lchain.at(j);
    rchain.at(lchain.at(j))=rchain.at(j);
    if(df)print(lchain,"lfc");
    if(df)print(rchain,"rgc");
  }
  if(df)print(lft,"lft");
  if(df)print(rgt,"rgt");
  li ans=0;
  rep(i,n+2){
    ans+=vec.at(i)*lft.at(i)*rgt.at(i);
  }
  printf("%ld\n",ans);
}

// pair 型の print (map 含む)
template<typename F,typename S>
void print_item(pair<F,S> x) {
  printf("(");
  print_item(x.first);
  printf(",");
  print_item(x.second);
  printf(")");
}



void print(auto& vec,string str){
  if(str!="") cout << str << ":";
  for(auto x: vec) {print_item(x); cout << " ";}
  cout << endl;
}


/// confirm df==0 ///
