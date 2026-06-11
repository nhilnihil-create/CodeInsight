#include<bits/stdc++.h>
using namespace std;
int main(){
    int aa;
    string a;
    cin>>a;
    aa=a.length();
    if(aa&1){cout<<"No"<<endl;return 0;}
    for(int i=0;i<aa/2;i++){
        if(a[i]=='p'&&a[aa-i-1]!='q'){
            cout<<"No"<<endl;
            return 0;
        }else
        if(a[i]=='q'&&a[aa-i-1]!='p'){
            cout<<"No"<<endl;
            return 0;
        }else
        if(a[i]=='b'&&a[aa-i-1]!='d'){
            cout<<"No"<<endl;
            return 0;
        }else
        if(a[i]=='d'&&a[aa-i-1]!='b'){
            cout<<"No"<<endl;
            return 0;
        }
    }cout<<"Yes"<<endl;
    return 0;
}