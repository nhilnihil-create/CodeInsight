#include<bits/stdc++.h>
using namespace std;
/*void copy(string a, char b[]){
    for(int i=0;i<a.size();i++){
        b.push_back(i);
        b.at(i)=a.at(i);
    }
}*/
int main(){
    string a;
    cin>>a;
    string b;
    b=a;
    int flag;
    for(int i=0;i<a.size();i++){
        flag=0;
        for(int j=0;j<a.size();j++){
            if(i==j)continue;
            if(a.at(i)==b.at(j)){
                flag=1;
                break;
            }
        }
        if(flag) break;
    }
    if(flag==1) cout<<"no"<<endl;
    else cout<<"yes"<<endl;
    
}