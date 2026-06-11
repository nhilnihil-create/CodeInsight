#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    string s;
    cin>>s;
    int len=s.length();
    int index=-1;
    for(int i=0;i<len-1;i++){
        if(s[i]==s[i+1]){
            index=i;
            break;
        }
    }
    if(index!=-1)
    cout<<index+1<<" "<<index+2;
    else{
        for(int i=1;i<len-1;i++){
            if(s[i-1]==s[i+1]){
                index=i;
                break;
            }
        }
        if(index==-1)cout<<"-1 -1";
        else cout<<index<<" "<<index+2;
    }
}