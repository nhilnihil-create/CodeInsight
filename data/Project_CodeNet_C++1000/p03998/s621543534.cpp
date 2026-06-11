#include<iostream>
#include<queue>
using namespace std;

int main(){
    string s,t,u;
    cin>>s>>t>>u;
    queue<char> a,b,c,now;
    for(int i=0;i<s.size();i++) a.push(s[i]);
    for(int i=0;i<t.size();i++) b.push(t[i]);
    for(int i=0;i<u.size();i++) c.push(u[i]);
    now=a;
    a.pop();
    while(1){
        char o=now.front();
        if(o=='a'){
            if(a.empty()){
                cout<<"A"<<endl;
                return 0;
            }
            now=a;
            a.pop();
        }
        if(o=='b'){
            if(b.empty()){
                cout<<"B"<<endl;
                return 0;
            }
            now=b;
            b.pop();
        }
        if(o=='c'){
            if(c.empty()){
                cout<<"C"<<endl;
                return 0;
            }
            now=c;
            c.pop();
        }
    }
}