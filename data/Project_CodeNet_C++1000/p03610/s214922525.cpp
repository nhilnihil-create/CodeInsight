#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    string t;
    for(int i=0,l=s.size();i<l;i+=2){
        t.push_back(s[i]);
    }
    cout<<t<<endl;
}
