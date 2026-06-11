#include <bits/stdc++.h>
#include <math.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    bool nn=false;bool ss=false;bool ee=false;bool ww=false;
    for(int i=0;i<=s.size()-1;i++){
      if(s.at(i)=='S'){ss=true;}
      if(s.at(i)=='N'){nn=true;}
      if(s.at(i)=='W'){ww=true;}
      if(s.at(i)=='E'){ee=true;}
    }
    if(ee!=ww){cout<<"No"<<endl;}
    else if(ss!=nn){cout<<"No"<<endl;}
    else{cout<<"Yes"<<endl;}
    return 0;
}