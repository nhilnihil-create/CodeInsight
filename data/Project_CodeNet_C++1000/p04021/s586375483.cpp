#include <bits/stdc++.h>
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)
#define invrep(i,n) for(int64_t i=n-1;i >= 0;i--)
#define _GLIBCXX_DEBUG
using namespace std;

int main(){
  int64_t n;
  cin >> n;
  vector<pair<int64_t,int64_t>> a(n);
  rep(i,n){
    int64_t hoge;
    cin >> hoge;
    a[i] = make_pair(hoge,i+1);
  }
  int64_t cnt=0;
  sort(a.begin(),a.end());
  rep(i,n){
    a[i].first = i+1;
    //cout << a[i].first << " " << a[i].second << endl;
    if(a[i].first % 2 != a[i].second % 2 ){
      cnt++;
    }
  }
  cout << cnt/2 << endl;
      
  
    
}