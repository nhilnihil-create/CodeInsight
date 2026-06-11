// luogu-judger-enable-o2
#include <iostream>
#include <string>
using namespace std;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    string s;
    cin>>s;
    int l=s.length();
    if(s[0]==s[l-1])
        if(l%2==0) cout<<"First"<<endl;
        else cout<<"Second"<<endl;
    else
        if(l%2==0) cout<<"Second"<<endl;
        else cout<<"First"<<endl;
    return 0;
}