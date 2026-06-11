#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  vector<int> num(100000);//1-index
  for(int i=0;i<N;i++){
    cin >> A.at(i);
    num.at(A.at(i))++;
  }
  int max_ans=0;
  for(int i=0;i<100000;i++){
    int ans;
    if(i==0){
      ans=num.at(0)+num.at(1);
    }
    else if(i==99999){
      ans=num.at(99998)+num.at(99999);
    }
    else{
      ans=num.at(i-1)+num.at(i)+num.at(i+1);
    }
    max_ans=max(max_ans,ans);
  }
  cout << max_ans << endl;
}