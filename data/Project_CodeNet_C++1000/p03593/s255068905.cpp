#include <bits/stdc++.h>
using namespace std;

int main(){
  int H,W;
  cin >> H >> W;
  vector<string> S(H);
  for(int i=0;i<H;i++)  cin >> S.at(i);

  vector<int> same(5,0);
  vector<vector<int>> x(H,vector<int>(W,0));
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      int cnt=0;
      if(x.at(i).at(j)==0){
        x.at(i).at(j)=1;
        cnt++;
      }
      if(x.at(i).at(W-1-j)==0){
        x.at(i).at(W-1-j)=1;
        cnt++;
      }
      if(x.at(H-1-i).at(j)==0){
        x.at(H-1-i).at(j)=1;
        cnt++;
      }
      if(x.at(H-1-i).at(W-1-j)==0){
        x.at(H-1-i).at(W-1-j)=1;
        cnt++;
      }
      same.at(cnt)++;
    }
  }

  vector<int> al(26,0);
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      al.at(S.at(i).at(j)-'a')++;
    }
  }
  for(int i=0;i<26;i++){
    while(al.at(i)!=0){
      bool flag=false;
      for(int j=4;j>=1;j--){
        if(same.at(j)==0) continue;
        if(al.at(i)<j)  continue;
        flag=true;
        same.at(j)--;
        al.at(i)-=j;
        break;
      }
      if(!flag){
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;

  return 0;
}