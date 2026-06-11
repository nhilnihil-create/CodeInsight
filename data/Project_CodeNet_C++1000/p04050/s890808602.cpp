//スマホコーディング
#include<iostream>
#include<algorithm>
#include<vector>;

using namespace std;

int n,m;
int a[100];

int main(){
  cin>>n>>m;
  int odds[2];
  int oddcnt=0;
  for (int i = 0; i < m; i++){
    cin>>a[i];
    if(a[i]&1) {
      oddcnt++;
      if(oddcnt==3){
        cout<<"Impossible"<<endl;
        return 0;
        }else{
        odds[oddcnt-1]=i;
        }
      }
    }
  if(oddcnt>=1) swap(a[0],a[odds[0]]);
  if(oddcnt>=2) swap(a[m-1],a[odds[1]]);
  for(int i = 0; i<m; i++) cout<<a[i]<<(i==n-1?"":" ");
  cout << endl;
  vector<int>b;
  for(int i=0; i< m; i++) {
    if(i==0){
      if(a[i]-1!=0)b.emplace_back(a[i]-1);
    }else if(i==m-1){
      b.emplace_back(a[i]+1);
      }else{
      b.emplace_back(a[i]);
      }
    }
  if(m==1)b.emplace_back(1);
  cout<<b.size()<<endl;
  for(int i=0;i<b.size();i++)cout<<b[i]<<(i==b.size()-1?"":" ");
  cout<<endl;
}
