#include <iostream>
using namespace std;

int d[13]={0,1,3,1,2,1,2,1,1,2,1,2,1};
int main(void){
    // Your code here!
    int x,y;
    cin>>x>>y;
    if(d[x]==d[y]){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
  return 0;
}
