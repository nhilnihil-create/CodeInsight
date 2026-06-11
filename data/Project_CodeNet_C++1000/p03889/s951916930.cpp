#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main(){
    string s;
    cin>>s;
    int n=s.size();
    bool ok=false;
    for(int i=0;i<n;i++){
        int j=n-i-1;
        if(s[i]=='q'&&s[j]=='p');
        else {
            if(s[i]=='b'&&s[j]=='d');
            else {
            if(s[i]=='d'&&s[j]=='b');
                  else {if(s[i]=='p'&&s[j]=='q');
                  else ok=true;
                  }
            }
        }
    }
    if(!ok){
        cout<<"Yes"<<endl;
    }
    else cout<<"No";
    return 0;
}