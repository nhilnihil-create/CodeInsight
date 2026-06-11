#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <set>
#include <iomanip>
#include <stdio.h>
#include <sstream>
#include <string>
using namespace std;
int main(void){
  int n;
  cin>>n;
  vector<long long int> hoge(n);
  for(long long int i=0; i<n; i++){
    cin>>hoge.at(i);
  }
  sort(hoge.begin(),hoge.end());
  vector<int> ans(n);
  bool can=true;
  for(int i=0; i<n; i++){
    if(n%2==0){
      if(hoge.at(i)%2!=0){
        ans.at(hoge.at(i))++;
      }else{
        can=false;
      }
    }else{
      if(hoge.at(i)%2==0){
        ans.at(hoge.at(i))++;
      }else{
        can=false;
      }
    }
  }

  if(can){
    long long int pre=1;
    for(int i=0; i<n; i++){
      if(ans.at(i)==0){
        continue;
      }
      if(n%2==0){
        if(ans.at(i)==2){
          pre*=2;
          pre%=1000000007;
        }else{
          pre=0;
          break;
        }
      }else{
        if(ans.at(i)==2){
          pre*=2;
          pre%=1000000007;
        }else if(!(ans.at(i)==1&&i==0)){
          pre=0;
          break;
        }
      }
    }
    cout<<pre<<endl;
  }else{
    cout<<0<<endl;
  }
}