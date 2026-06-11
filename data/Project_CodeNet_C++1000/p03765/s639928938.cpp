#include<vector>
#include<iostream>
using namespace std;
#define df 0
#define rep(i,n) for(int i=0;i<(n);i++)

typedef long int li;


int main(){
  if(df) printf("*debug mode*\n");
  string s,t; cin >>s >>t;
  vector<vector<int>> vec(2,vector<int>(1,0));
  rep(j,2){
    int n=(j?t:s).size(),temp=0;
    rep(i,n){
      temp+=((j?t:s).at(i)=='A')?1:-1;
      vec.at(j).push_back(temp);
    }
  }
  auto get=
    [&](int a,int b,int i){ 	// get[a,b)  0-origin
      return vec.at(i).at(b)-vec.at(i).at(a);
    };
  int q; cin >>q;
  rep(i,q){
    int a,b,c,d; cin >>a >>b >>c >>d; a--; c--;
    printf("%s\n",(get(a,b,0)-get(c,d,1))%3?"NO":"YES");
  }
}



/// confirm df==0 ///
