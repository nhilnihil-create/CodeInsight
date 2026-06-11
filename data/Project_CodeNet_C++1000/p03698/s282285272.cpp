#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    string s;
    cin>>s;
    vector<int>a(26);
    bool flag=true;
    for(int i=0;i<s.size();i++){
        a[s[i]-'a']++;
        if(a[s[i]-'a']>1)flag=false;
    }
    if(flag)cout<<"yes"<<endl;
    else cout<<"no"<<endl;
    return 0;
}