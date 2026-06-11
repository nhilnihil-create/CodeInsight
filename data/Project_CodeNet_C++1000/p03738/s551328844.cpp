#include<iostream>
using namespace std;

int main(){
    string a,b;
    cin>>a>>b;

    if(a.size()>b.size())cout<<"GREATER"<<endl;
    else if(a.size()<b.size())cout<<"LESS"<<endl;
    else {
        for(int i=0;i<a.size();i++){
            if(a[i]==b[i]&&i!=a.size()-1)continue;
            if(a[i]>b[i]){
                cout<<"GREATER"<<endl;
                break;
            }else if(a[i]<b[i]){
                cout<<"LESS"<<endl;
                break;
            }
            cout<<"EQUAL"<<endl;
        }
    }
    return 0;
}