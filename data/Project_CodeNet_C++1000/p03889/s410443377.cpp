#include<cstdio>
#include<iostream>
#include<cstring>
#include<stack>
using namespace std;
stack<char>s;
string a;
int main(){
    cin>>a;
    int n=a.size();
    for(int i=0;i<n;i++){
        s.push(a[i]);
    }
    bool ju=1;
    for(int i=0;i<n;i++){
        char top=s.top();
        if(top=='b') top='d';
        else if(top=='d') top='b';
        else if(top=='p') top='q';
        else if(top=='q') top='p';
        if(top==a[i]) {
            ju=1;
            s.pop();
        }
        else {
            ju=0;
            break;
        }
    }
    if(ju==0) printf("No");
    else printf("Yes");
    return 0;
}