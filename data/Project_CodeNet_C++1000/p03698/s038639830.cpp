#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=0;
    char s[27];
    cin>>s;
    for(int i=0;i<strlen(s);i++){
        for(int j=0;j<strlen(s);j++){
            if(j==i)
             continue;
            else if(s[j]==s[i])
             {t++;break;}
        }
    }
    if(t>0)
     cout<<"no";
    else 
     cout<<"yes";
    return 0;
}
     
   


