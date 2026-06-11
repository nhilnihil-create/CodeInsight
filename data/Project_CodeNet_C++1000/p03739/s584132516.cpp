#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int>data(N);
  int y;
  cin >> y;
  data.at(0)=y;
  for(int i=1;i<N;i++){
    int x;
    cin >> x;
    data.at(i)=data.at(i-1)+x;
  }
  int64_t sei_ans=0;
  int64_t hu_ans=0;
  int zyoutai=0;
  for(int i=0;i<N;i++){
    if(i%2==0){
      int a=max(0,1-data.at(i)-zyoutai);
      zyoutai+=a;
      sei_ans+=a;
    }
    else{
      int a=max(0,1+data.at(i)+zyoutai);
      zyoutai-=a;
      sei_ans+=a;
    }
  }
  zyoutai=0;
  for(int i=0;i<N;i++){
    if(i%2!=0){
      int a=max(0,1-data.at(i)-zyoutai);
      zyoutai+=a;
      hu_ans+=a;
    }
    else{
      int a=max(0,1+data.at(i)+zyoutai);
      zyoutai-=a;
      hu_ans+=a;
    }
  }
  cout << min(sei_ans,hu_ans) << endl;
}
