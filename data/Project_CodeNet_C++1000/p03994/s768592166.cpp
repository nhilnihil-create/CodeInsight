#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    string s;
    cin>>s;
    int k;
    cin>>k;
    int a[s.size()];
    int sum=0;
    for(int i=0;i<s.size();i++){
        a[i]=s[i]-'a';
        if(a[i]){
            if(26-a[i]<=k){
                k-=(26-a[i]);
                a[i]=0;
            }
        }
    }
    k%=26;
    if(k){
        a[s.size()-1]=(a[s.size()-1]+k)%26;
    }
    for(int i=0;i<s.size();i++)cout<<char(a[i]+'a');
    cout<<endl;
    return 0;
}