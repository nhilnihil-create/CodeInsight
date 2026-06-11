#include<iostream>
#include<vector>
#include<string>

using namespace std;

#define int long long

signed main(){

  int H, W;
  int N;
  vector<int> A;
  vector<vector<int>> ans;

  cin>>H>>W;

  cin>>N;

  A.resize(N);

  ans.resize(H+1);
  
  for(int i = 0, j = 0; i < N; i++){
    
    cin>>A[i];
    
    while(A[i]){
      
      if(ans[j].size() == W) j++;
      
      ans[j].push_back(i+1);
      
      A[i]--;
    }
  }

  for(int i = 0; i < H; i+=2){ //cout<<"A"<<endl;
    for(int j = 0; j < W; j++){
      if(j) cout<<" ";
      cout<<ans[i][j];
    }
    cout<<endl;
    
    //cout<<i+1<<" H = "<<H<<endl;
    
    if(i+1 >= H) break;
    // cout<<"B"<<endl;
    for(int j = 0; j < W; j++){
      if(j) cout<<" ";
      cout<<ans[i+1][W-j-1];
    }
    cout<<endl;
  }

  return 0;
}