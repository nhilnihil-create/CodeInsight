#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  int n;
  cin>>n;
  int max=0;
  int x=0;
  for(int i=0;i<n;i++){
    char s;
    cin>>s;
    if(s=='I'){
      x++;
    }
    if(s=='D'){
      x--;
    }
    if(x>max){
      max=x;
    }
  }
  cout<<max<<endl;
}