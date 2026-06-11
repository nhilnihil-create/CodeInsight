#include <bits/stdc++.h>
using namespace std;



int main(){
  int N;
  cin>>N;
  
  vector<int> vec(N);
  for(int i=0;i<N;i++){
    cin>>vec.at(i);
  }
  vector<int> ret;
  vector<int> rett;
  for(int i=0;i<N;i++){
    int a=i;
    int b=vec.at(i);
    if(a%2==1){
      ret.push_back(b);
    }
    else{
      rett.push_back(b);
    }
  }
  int NNN=ret.size();
  int NN=rett.size();
  if(N==1){
    cout<<vec.at(0)<<endl;
    return 0;
  }
  if((N-1)%2==0){
  	for(int i=NN-1;i>=0;i--){
    	cout<<rett.at(i)<<" ";
  	}
 	 for(int i=0;i<NNN-1;i++){
    	cout<<ret.at(i)<<" ";
  	}
  	cout<<ret.at(NNN-1)<<endl;
  }
  else{
    for(int i=NNN-1;i>=0;i--){
    	cout<<ret.at(i)<<" ";
  	}
 	 for(int i=0;i<NN-1;i++){
    	cout<<rett.at(i)<<" ";
  	}
  	cout<<rett.at(NN-1)<<endl;
  }
}