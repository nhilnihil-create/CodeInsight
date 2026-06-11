#include <bits/stdc++.h>
using namespace std;

class Union_Find{
private:
  vector<int64_t> par;
  vector<int64_t> rank;
  vector<int64_t> num;

  int64_t find(int64_t x){
    if(par.at(x)==x){
      return x;
    }else{
      return par.at(x)=find(par.at(x));
    }
  }

public:
  Union_Find(int64_t n){
    par.resize(n);
    rank.resize(n,0);
    num.resize(n,1);
    for(int64_t i=0;i<n;i++){
      par.at(i)=i;
    }
  }

  void unite(int64_t x,int64_t y){
    x=find(x);
    y=find(y);
    if(x==y){
      return;
    }
    if(rank.at(x)<rank.at(y)){
      par.at(x)=y;
      num.at(y)+=num.at(x);
    }else if(rank.at(x)>rank.at(y)){
      par.at(y)=x;
      num.at(x)+=num.at(y);
    }else{
      par.at(x)=y;
      rank.at(y)++;
      num.at(y)+=num.at(x);
    }
  }

  bool same(int64_t x,int64_t y){
    return find(x)==find(y);
  }

  int64_t size(int64_t x){
    return num.at(find(x));
  }

};

int main(){
  Union_Find uni(13);
  uni.unite(1,3);
  uni.unite(3,5);
  uni.unite(5,7);
  uni.unite(7,8);
  uni.unite(8,10);
  uni.unite(10,12);
  uni.unite(4,6);
  uni.unite(6,9);
  uni.unite(9,11);
  int x,y;
  cin >> x >> y;
  if(uni.same(x,y)){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  return 0;
}
