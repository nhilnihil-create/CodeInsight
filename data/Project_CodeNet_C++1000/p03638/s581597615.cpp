#include <bits/stdc++.h>
using namespace std;
int main() {
  int H,W,N,h=0,w=0,a=0;
  cin>>H>>W;
  cin>>N;
  vector<int>M(N);
  vector<vector<int>> ans(H, vector<int>(W));
  for(int i=0;i<N;i++){
  	cin>>M.at(i);
  }
  for(int j=0;j<=N-1;j++){
    for(int k=1;k<=M.at(j);k++){
    	ans.at(h).at(w)=j+1;
    if(h!=H-1 && w%2==0){
    	h++;
      }else if(h==H-1 && w%2==0){
        w++;
        
      }else if(h!=0 && w%2==1){
        h--;
      }else {
        w++;
        
      }
    }
  }
  for(int l=0;l<H;l++){
  	for(int m=0;m<W-1;m++){
    	cout<<ans.at(l).at(m)<<" ";
    }
    cout<< ans.at(l).at(W-1)<<endl;
  }
   
}