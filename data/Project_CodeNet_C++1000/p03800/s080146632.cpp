#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> P2;
int next_animal(int a,int b,int c){
  //a:左の動物、b:真ん中の動物、c:oか×か
  //ひつじ:0 おおかみ:1
  if(b==1) c=(c+1)%2;
  if(c==0) return a;
  else return (a+1)%2;
}
int main(){
  int n;
  cin>>n;
  vector<int> vec;
  for(int i=0;i<n;i++){
    char a;
    cin>>a;
    if(a=='o') vec.push_back(0);
    else vec.push_back(1);
  }
  for(int i=0;i<2;i++){
    for(int j=0;j<2;j++){
      vector<int> ans;
      ans.push_back(i);
      ans.push_back(j);
      for(int k=1;k<n-1;k++){
        int ps=ans.size()-1;
        ans.push_back(next_animal(ans[ps-1],ans[ps],vec[ps]));
      }
      if(next_animal(ans[n-2],ans[n-1],vec[n-1])==i&&next_animal(j,i,vec[0])==ans[n-1]){
        for(int k=0;k<n;k++) cout<<(ans[k]==0?'S':'W');
        cout<<endl;
        return 0;
      }
    }
  }
  cout<<-1<<endl;
  return 0;
}
