#include<iostream>
#include<string>

using namespace std;

int main(){
    string s;
    int a,z;

    cin>>s;
        for(int i=0;i<s.size();++i){
            if(s[i]=='A'){
                a=i;
                break;
            }
        }
            for(int i=a;i<s.size();++i){
                if(s[i]=='Z'){
                    z=i;
                }
            }
        cout<<z-a+1;
}