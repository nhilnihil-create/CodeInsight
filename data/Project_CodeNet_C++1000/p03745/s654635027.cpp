#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  pair<int,int>data=make_pair(0,0);
  int y;
  cin >> y;
  data.first=y;
  int count=1;
  for(int i=1;i<N;i++){
    int x;
    cin >> x;
    if(x>data.first&&data.second==2){
      count++;
      data.second=0;
    }
    else if(x<data.first&&data.second==1){
      count++;
      data.second=0;
    }
    else if(x>data.first&&data.second==0){
      data.second=1;
    }
    else if(x<data.first&&data.second==0){
      data.second=2;
    }
    data.first=x;
  }
  cout << count << endl;
}
