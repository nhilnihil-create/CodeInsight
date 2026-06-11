#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long LL;

int main(){
  LL h,w,n;
  cin >> h >> w >> n;
  vector<LL> ans(10,0);
  ans[0]=(h-2)*(w-2);
  int a,b;
  map<int,set<int>> field;
  field[-2]=set<int>();
  field[-1]=set<int>();
  field[h]=set<int>();
  field[h+1]=set<int>();
  map<int,set<int>>::iterator mitr;
  set<int>::iterator sitr;
  vector<vector<int>> f(6,vector<int>(6));
  int count;
  for(int i=0;i<n;i++){
    cin >> a >> b;
    a--;
    b--;
    for(int j=0;j<6;j++){
      for(int k=0;k<6;k++){
        f[j][k]=0;
      }
    }
    mitr=field.find(a);
    if(mitr==field.end()){
      field[a]=set<int>();
      mitr=field.find(a);
      mitr->second.insert(-2);
      mitr->second.insert(-1);
      mitr->second.insert(w);
      mitr->second.insert(w+1);
    }
    sitr=mitr->second.find(b);
    if(sitr==mitr->second.end()){
      mitr->second.insert(b);
    }
    mitr=field.lower_bound(a-2);
    for(;mitr->first<=a+2&&mitr!=field.end();mitr++){
      sitr=mitr->second.lower_bound(b-2);
      for(;(*sitr)<=b+2&&sitr!=mitr->second.end();sitr++){
        f[mitr->first-a+3][(*sitr)-b+3]++;
      }
    }
    for(int i=1;i<6;i++){
      for(int j=1;j<6;j++){
        f[i][j]+=f[i-1][j]+f[i][j-1]-f[i-1][j-1];
      }
    }
    for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
        if(0<=a-2+i&&a+i<h&&0<=b-2+j&&b+j<w){
          count=f[i+3][j+3]-f[i+3][j]-f[i][j+3]+f[i][j];
          ans[count-1]--;
          ans[count]++;
        }
      }
    }
  }
  for(int i=0;i<10;i++){
    cout << ans[i] << endl;
  }
  return 0;
}
