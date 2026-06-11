#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
    cin>>s;
    string str=s;
    reverse(s.begin(),s.end());
    for(int i=0;i<s.size();++i){
        s[i]=='b'? s[i]='d':
		s[i]=='d'? s[i]='b':
        s[i]=='p'? s[i]='q':
        s[i]=='q'? s[i]='p': i+=0;
    }
    s==str?cout<<"Yes"<<endl:cout<<"No"<<endl;
    return 0;
}