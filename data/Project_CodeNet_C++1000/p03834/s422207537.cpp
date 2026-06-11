#include<iostream>
#include<algorithm>

using namespace std;

#define REP(s,e) for(int i=(s);i<(e);i++)

int main(){
    string s;
    cin>>s;

    REP(0,s.size()){
        if(s[i]==',') s[i]=' ';
    }

    cout<<s<<endl;
}
