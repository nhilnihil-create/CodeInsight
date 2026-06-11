#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long LL;

int uf[2][200000];

struct city{
  int dou;
  int tetu;
  int id;
  bool operator<(const struct city & right) const{
    return (dou==right.dou?tetu<right.tetu:dou<right.dou);
  }
};

int find(int i,int a){
  if(a==uf[i][a]) return a;
  else return uf[i][a]=find(i,uf[i][a]);
}

void uni(int i,int a,int b){
  a=find(i,a);
  b=find(i,b);
  if(a==b) return;
  uf[i][a]=b;
  return;
}

int main(){
  int n,k,l;
  cin >> n >> k >> l;
  for(int i=0;i<n;i++){
    uf[0][i]=uf[1][i]=i;
  }
  int p,q;
  for(int i=0;i<k;i++){
    cin >> p >> q;
    uni(0,--p,--q);
  }
  for(int i=0;i<l;i++){
    cin >> p >> q;
    uni(1,--p,--q);
  }
  vector<struct city> kumi(n);
  for(int i=0;i<n;i++){
    kumi[i]={find(0,i),find(1,i),i};
  }
  sort(kumi.begin(),kumi.end());
  int count=0;
  vector<int> ans(n,0);
  vector<int> kosu(n,0);
  kosu[0]=1;
  for(int i=1;i<n;i++){
    if(kumi[i].dou!=kumi[i-1].dou||kumi[i].tetu!=kumi[i-1].tetu) count++;
    ans[kumi[i].id]=count;
    kosu[count]++;
  }
  for(int i=0;i<n;i++){
    cout << kosu[ans[i]] << endl;
  }
  return 0;
}
