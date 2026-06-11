#include <bits/stdc++.h>
using namespace std;

int main(){
    string x;cin>>x;
    int i=0;
    int k=x.size();
    while(i<k){
      if(i>=0&&i<k-1){
        if(x.substr(i,2)=="ST"){
            x.replace(i,2,"");
            i=i-2;
            k=x.size();
            }
    }
    i++;
    }
    cout<<x.size()<<endl;
}