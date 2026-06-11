#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s; int p=0, answer=0;
    for(int i =0; i<s.size(); i++){
        if(p>0){
            if(s[i]=='g') answer++;
            p--;
        }
        else{
            if(s[i]=='p') answer--;
            p++;
        }
    }
    cout<<answer;
    return 0;
}