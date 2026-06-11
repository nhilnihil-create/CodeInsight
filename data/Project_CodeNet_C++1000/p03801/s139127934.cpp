// vector の添字と読み込んだ順番を勘違いしていた
// map とか使って若干高速化．．
#include<vector>
#include<map>
#include<iostream>
using namespace std;
#define df 0
#define rep(i,n) for(int i=0;i<(n);i++)
#define repa(i,a,n) for(int i=(a);i<(n);i++)
typedef long int li;

void print(vector<li> vec,string str=""){
  if(not (str=="")) cout << str << ":";
  for(auto x:vec) printf("%ld ",x);
  printf("\n");
}

void print(map<int,int> mp,string str=""){
  if(not (str=="")) cout << str << ":";
  for(auto x:mp) printf("(%d,%d)",x.first,x.second);
  printf("\n");
}
void print(vector<pair<int,int>> mp,string str=""){
  if(not (str=="")) cout << str << ":";
  for(auto x:mp) printf("(%d,%d)",x.first,x.second);
  printf("\n");
}
void print(  map<int,pair<int,int>> mp,string str=""){
  if(not (str=="")) cout << str << ":";
  for(auto x:mp) printf("(%d,%d,%d)",x.first,x.second.first,x.second.second);
  printf("\n");
}


int main(){
  if(df) printf("*debug mode*\n");
  int n;cin >> n;
  int M=0;
  map<int,pair<int,int>> dict;
  dict[0]=make_pair(0,0);
  vector<li> mul(1,0),rem(1,0);
  int cnt=1;
  rep(i,n){
    int a; cin >>a;
    if(df){printf("read:%d ,%d ",a,M); cout << endl;}
    if(a>M){
      M=a;
      dict[a]=make_pair(i+1,cnt++);
      mul.push_back(1);
      rem.push_back(0);
      if(df)printf("add %d\n",i+1);
    } else if(a==M){
      auto& x=*(mul.rbegin());
      x++;
    } else {
      auto itr=dict.upper_bound(a);
      if(itr==dict.begin())return 0;
      auto x=*(--itr);
      if(df){
	printf("itr:%d  %d",x.second.first,x.second.second);
	cout <<endl;
      }
      mul.at(x.second.second)++;
      rem.at(x.second.second+1)+=a-x.first;
      if(df)printf("mul%d:+1, rem%d:+%d\n",x.second.second,x.second.second+1,a-x.first);
    }
    if(df){
      print(dict,"dict");
      print(mul,"mul");
      print(rem,"rem");
    }
  }
  
  if(df)printf("a");// cout  <<endl;
  for(int i=mul.size()-2;i>0;i--){
    mul.at(i)+=mul.at(i+1);
  }
  if(df){
    print(mul,"mul");
    print(rem,"rem");
  }
  vector<pair<int,int>> dictv;
  for(auto x:dict){
    dictv.push_back(make_pair(x.first,x.second.first));
  }
  auto itr=dict.begin();
  repa(i,1,mul.size()){
    rem.at(i)+=(dictv.at(i).first-dictv.at(i-1).first)*mul.at(i);
  }
  if(df){
    print(dictv);
    print(mul,"mul");
    print(rem,"rem");
  }
  dictv.push_back(make_pair(n+1,n+1));
  int k=1;
  repa(i,1,n+1){
    if(df)printf("k%di%d ",k,i);
    if(dictv.at(k).second==i){
      printf("%ld\n",rem.at(k));
      k++;
    }else{
      printf("0\n");
    }
  }

  if(df)printf("done\n");
}

/// confirm df==0 ///
