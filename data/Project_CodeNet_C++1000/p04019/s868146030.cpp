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
    if(ss==true&&nn==true){if(ee==true&&ww==false){cout<<"No"<<endl;}
                           else if(ee==false&&ww==true){cout<<"No"<<endl;}
                           else if(ee==true&&ww==true){cout<<"Yes"<<endl;}
                           else if(ee==false&&ww==false){cout<<"Yes"<<endl;}
                           }
    else if (ss==false&&nn==false){if(ee==true&&ww==false){cout<<"No"<<endl;}
                           else if(ee==false&&ww==true){cout<<"No"<<endl;}
                           else if(ee==true&&ww==true){cout<<"Yes"<<endl;}
                           else if(ee==false&&ww==false){cout<<"Yes"<<endl;}
                           }
    else{cout<<"No"<<endl;}
    return 0;
}