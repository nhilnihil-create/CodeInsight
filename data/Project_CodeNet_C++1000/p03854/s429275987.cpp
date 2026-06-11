#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;cin>>s;
    string t1,t2,t3,t4;
    t1 = "dream";
    t2 = "dreamer";
    t3 = "erase";
    t4 = "eraser";
    
    reverse(s.begin(), s.end());
    reverse(t1.begin(), t1.end());
    reverse(t2.begin(), t2.end());
    reverse(t3.begin(), t3.end());
    reverse(t4.begin(), t4.end());
    
    while(s.size()>0){
        string tmp;
        if(s.substr(0,t1.size()) ==t1 ) s = s.substr(t1.size());
        else if(s.substr(0,t2.size()) ==t2 ) s = s.substr(t2.size());
        else if(s.substr(0,t3.size()) ==t3 ) s = s.substr(t3.size());
        else if(s.substr(0,t4.size()) ==t4 ) s = s.substr(t4.size());
        else{
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
	return 0;
}