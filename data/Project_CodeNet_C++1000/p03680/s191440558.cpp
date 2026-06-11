#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,cnt=1,now;
  cin >> n;
  vector<int> buttons(n);
  for(int i=0;i<n;i++){
    cin >> buttons.at(i);
  }
  now=buttons.at(0);
  while(now!=2){
    now=buttons.at(now-1);
    cnt++;
    if(cnt>n){cnt=-1;break;}
  }
  cout << cnt << endl;
}