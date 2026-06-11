#include <iostream>
#include <vector>
#include <algorithm>
#define all(a) a.begin(),a.end()
using namespace std;
typedef pair<int,int> P;

int main(){
  int n;
  cin >> n;
  vector<P> a(n);
  for(int i=0;i<n;i++){
    cin >> a[i].first; a[i].first--;
    a[i].second=i+1;
  }
  sort(all(a));
  vector<int> ans(n*n);
  for(int i=0;i<n;i++) ans[a[i].first]=a[i].second;
  int now=0;
  int k=a[now].second-1;
  int nnow=0;
  int nk=n-a[nnow].second;
  for(int i=0;i<n*n;i++){
    if(ans[i]==0){
      while(k==0){
        now++;
        k=a[now].second-1;
      }
      ans[i]=a[now].second;
      k--;
      if(now>=n){
        //cerr << i << endl;
        while(nk==0){
          nnow++;
          nk=n-a[nnow].second;
        }
        ans[i]=a[nnow].second;
        nk--;
      }
    }
  }
  //for(int i=0;i<n;i++) cout << a[i].first << ' ' << a[i].second << endl;
  vector<int> check(n);
  int x=0;
  for(int i=0;i<n*n;i++){
    check[ans[i]-1]++;
    if(a[x].first==i){
      if(check[ans[i]-1]!=ans[i]){
        cout << "No" << endl;
        return 0;
      }
      x++;
    }
  }
  cout << "Yes" << endl;
  for(int i=0;i<n*n;i++) cout << ans[i] << ' ';
  cout << endl;
}