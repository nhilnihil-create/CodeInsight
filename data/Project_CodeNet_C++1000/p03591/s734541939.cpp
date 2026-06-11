#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);

    string s;
    cin>>s;
    string yaki="YAKI";
    if(s.size()<4){
        cout<<"No"<<endl;
        return 0;
    }
    bool ok=true;
    for(int i=0;i<4;i++){
        if(s[i]!=yaki[i]) ok=false;
    }
    if(ok){
        cout<<"Yes"<<endl;
        return 0;
    }
    else cout<<"No"<<endl;
    
    
}