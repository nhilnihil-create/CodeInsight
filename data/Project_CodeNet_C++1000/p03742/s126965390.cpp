#include<iostream>
#include<algorithm>
using namespace std;
int main(){
  long long a,b;cin>>a>>b;
  if(abs(a-b)>1){
    cout<<"Alice"<<endl;
  }else{
    cout<<"Brown"<<endl;
  }
	return 0;
}