#include <bits/stdc++.h>
using namespace std;

int main(){
  int H,W;
  cin>>H>>W;
  map<char,int>mp;
  char temp;
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin>>temp;
      mp[temp]++;
    }
  }
  int N1=0;
  int N2=0;
  int N4=0;
  
  for(auto itr=mp.begin();itr !=mp.end();itr++){
    if(itr->second == 1){
      N1++;
    }
    if(itr->second == 2){
      N2++;
    }
    if(itr->second == 3){
      N2++;
      N1++;
    }
    if(itr->second == 4){
      N4++;
    }
    if((itr->second)>4){
      if((itr->second)%4==0){
        N4+=(itr->second)/4;
      }
      if((itr->second)%4 == 1){
        N4+=(itr->second)/4;
        N1++;
      }
      if((itr->second)%4 == 2){
        N4+=(itr->second)/4;
        N2++;
      }
      if((itr->second)%4 == 3){
        N4+=(itr->second)/4;
        N2++;
        N1++;
      }      
    }
  }
  
  //cout<<N1<<" "<<N2<<" "<<N4<<endl;
  
  if(H%2 == 1){
    if(W%2 == 1){
      if(N1 == 1 && N4>=(H-1)*(W-1)/4){
        cout<<"Yes"<<endl;
        return 0;
      }
      else cout<<"No"<<endl;
      return 0;
    }
    else{
      if(N1 >=1 || N4<W*(H-1)/4){
        cout<<"No"<<endl;
        return 0;
      }
      cout<<"Yes"<<endl;
      return 0;
    }
  }
  if(H%2 == 0){
    if(N1>=1){
      cout<<"No"<<endl;
      return 0;
    }
    if(W%2 == 1){
      if(N2 > H/2){
        cout<<"No"<<endl;
        return 0;
      }
    }
    if(W%2 == 0){
      if(N2 >=1){
        cout<<"No"<<endl;
        return 0;
      }
    }
    cout<<"Yes"<<endl;
    return 0;
  }
  //cout<<"#"<<endl;
  return 0;
}

  