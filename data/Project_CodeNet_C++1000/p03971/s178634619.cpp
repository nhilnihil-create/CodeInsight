#include <bits/stdc++.h>
using namespace std;

int main(){
    long n,a,b;cin>>n>>a>>b;
    string s;cin>>s;
    long na=0;
    long nb=0;
    for(int i=0;i<n;i++){
        char k=s.at(i);
        if(k=='a'){
            if(na+nb<a+b){
                cout<<"Yes"<<endl;
                na++;
            }else cout<<"No"<<endl;
        }
        if(k=='b'){
            if(na+nb<a+b && nb<b){
                cout<<"Yes"<<endl;
                nb++;
            }else cout<<"No"<<endl;
        }
        if(k=='c'){
            cout<<"No"<<endl;
        }
    }
}