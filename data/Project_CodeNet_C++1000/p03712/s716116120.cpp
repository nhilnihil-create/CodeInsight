#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int h,w;
  cin >> h>>w;
  vector <char> a(h*w);
  
  for(int i=0;i<h*w;i++){
    cin >> a.at(i);
  }
  
  for(int i=0;i<w+2;i++){
    cout<<"#";
  }
  
  cout<<endl;
  
  for(int i=0;i<h*w;i++){
    if(i%w==0&&(i+1)%w==0){
      cout << "#"<<a.at(i)<<"#"<<endl;
    }
    else if(i%w==0&&(i+1)%w!=0){
      cout<< "#"<< a.at(i);
    }
    
    else if(i%w!=0&&(i+1)%w==0){
      cout << a.at(i)<<"#"<<endl;
    }
    else{
      cout << a.at(i);
    }
  }
  
  for(int i=0;i<w+2;i++){
    cout<<"#";
  }
  
  cout<<endl;
  
}
  
  