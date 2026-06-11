#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<stack>
using namespace std;
stack<char>ss;
string a;
int main(){
    cin>>a;
    for(int i=0;i<a.size();i++)ss.push(a[i]);
    int PD=1;
    for(int i=0;i<a.size();i++){
        char topm=ss.top();
        if(topm=='b') topm='d';
        else if(topm=='d') topm='b';
        else if(topm=='p') topm='q';
        else if(topm=='q') topm='p';
        if(topm==a[i])ss.pop();
        else {
            PD=0;
            break;
        }
    }
    if(PD!=0) cout<<"Yes";
    else cout<<"No";
    return 0;
}