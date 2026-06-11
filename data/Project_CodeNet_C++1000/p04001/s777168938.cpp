#include<bits/stdc++.h>
using namespace std;

int main(){
  string N;
  cin >> N;
  
  int d=N.size();
  long long sum=0;
  for(int bit=0; bit <(1<<(d-1)); bit++){
    string fml;
    fml.push_back(N[0]);
    for(int i=0; i<d-1; i++){
      if(bit & (1<<i)){
        fml.push_back('+');
        fml.push_back(N[i+1]);
      }else{
        fml.push_back(N[i+1]);
      }
    }
    long long add=0;
    for(int i=0; i<fml.size(); i++){
      if(fml[i]=='+'){
        sum+=add;
        add=0;
      }else{
        add*=10;
        add+=fml[i]-'0';
        if(i==fml.size()-1) sum+=add;
      }
    }
  }
  cout << sum <<endl;
}