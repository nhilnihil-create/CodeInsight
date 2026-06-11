#include<iostream>
#include<cstring>
using namespace std;

void solve(const string&s){
    int l=s.length();
    bool flag[26]={0};
    for(int i=0;i<l;i++){
        if(flag[s[i]-'a']){
            cout<<"no"<<endl;
            return;
        }
        flag[s[i]-'a']=1;
    }
    cout<<"yes"<<endl;
}
int main(){
    string s;
    cin>>s;
    solve(s);
    return 0;
}
