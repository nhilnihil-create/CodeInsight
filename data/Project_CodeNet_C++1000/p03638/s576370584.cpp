#include <iostream>
using namespace std;

int main(int argc, char *argv[]){
  int H,W,N;
  cin>>H>>W;
  cin>>N;
  int M[H+1][W+1];
  int A[N+1];
  A[0]=0;
  for(int i=1; i<N+1; i++){
   // cout<<i<<endl;
    int a;
    cin>>a;
    A[i]=a;
  }
  for(int i=1; i<H+1; i++){
    for(int j=1; j<W+1; j++){
     	M[i][j]=-1;
    }
   }
  
  bool ret=false;
  int h=1,w=1;
  for(int j=1; j<N+1; j++){
    for(int i=1;i<=A[j]; i++){
      //cout<<w<<" ";
      if(w==0){
	w++;
	h++;
	ret=false;
      }
      if(w<=W){
	if(ret==false){
	  M[h][w]=j;
	  w++;
	}
	else{
	  M[h][w]=j;
	  w--;
	}
      }
      if(ret==false){
	if(w>W){
      w--;
	  M[h][w]=j;
	  h++;
	  ret=true;
	}
      }
    }
  }
  
  for(int i=1; i<H+1; i++){
    for(int j=1; j<W+1; j++){
     // cout<<i<<" "<<j<<endl;
        cout<<M[i][j]<<" ";
    }
    cout<<endl;
  }
}


 