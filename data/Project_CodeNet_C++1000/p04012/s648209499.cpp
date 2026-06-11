#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

int main(){
    string s;
    cin>>s;
    vector<int>a(26);
    for(int i=0;i<s.size();i++){
        a[s[i]-'a']++;
    }
    bool flag=true;
    for(int i=0;i<26;i++){
        if(a[i]%2!=0)flag=false;
    }
    if(flag==true)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}