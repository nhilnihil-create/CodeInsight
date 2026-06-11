#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
int main() {
	string s,t;
    cin>>s;
    t=s;
    reverse(t.begin(),t.end());
    for(int i=0;i<s.size();i++){
        if(s[i]=='p'&&t[i]=='q');
        else if(s[i]=='q'&&t[i]=='p');
        else if(s[i]=='b'&&t[i]=='d');
        else if(s[i]=='d'&&t[i]=='b');
        else{
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
	return 0;
}