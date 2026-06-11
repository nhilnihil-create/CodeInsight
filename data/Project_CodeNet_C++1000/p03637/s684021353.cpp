#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin>>N;
    int x=0;
    int y=0;
    int z=0;
    vector<int> a(N);
    for(int i=0;i<N;i++){
      cin>>a[i];
    }
    for(int i=0;i<N;i++){
      if(a[i]%4==0){
          x++;
          a[i]/=4;
      }
      else if(a[i]%2==0){
        y++;
      }
    }
      if((x*2+y)>=(N/2)*2){
        cout<<"Yes"<<endl;
      }
      else{
        cout<<"No"<<endl;
      }
    return 0;
}


