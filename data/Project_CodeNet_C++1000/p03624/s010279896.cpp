#include<iostream>
#include<string>
using namespace std;

int main(){
    string s;
    cin>>s;
    int ans;
    int a[26]={0};
    for(int i=0;i<s.size();i++){
        a[s[i]-'a']++;
    }
  	bool flag=false;
    for(int i=0;i<26;i++){
        if(a[i]==0){
            cout<<char(i+'a');
          	flag=true;
            break;
        }
    }
  	if(flag==false)cout<<"None"<<endl;
   
    return 0;
}