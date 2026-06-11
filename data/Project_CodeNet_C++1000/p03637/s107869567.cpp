#include <bits/stdc++.h>
using namespace std;
int main() {
  int N,count4=0,count2=0;
  cin>>N;
  vector<int>A(N);
  for(int i=0;i<N;i++){
  	cin>>A.at(i);
  }
  for(int j=0;j<N;j++){
  	if(A.at(j)%4==0){
    	count4++;
        continue;
    }else if(A.at(j)%2==0){
    	count2++;
    }
  }
  if(count4>=N/2){
  	cout<<"Yes"<<endl;
    
  }else if(count2>=N-2*count4){
    cout<<"Yes"<<endl;
    
  }else{
  	cout<<"No"<<endl;
    
  }
}