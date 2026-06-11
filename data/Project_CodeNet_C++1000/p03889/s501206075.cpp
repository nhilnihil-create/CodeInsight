#include<bits/stdc++.h>
using namespace std;
int main(){
    string a;
    char k;
    cin>>a;
    string b="";
    for(int i=a.length()-1;i>=0;i--)
    {
        k=a[i];
        switch(k)
        {
            case 'b':b+="d";break;
            case 'd':b+="b";break;
            case 'p':b+="q";break;
            case 'q':b+="p";break;
        }
    }
    if(a==b) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}