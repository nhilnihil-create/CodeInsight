#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    char s[100000];
    cin>>s;
    for(int i=0;i<strlen(s);i++){
        if(i==0 || i%2==0)
         cout<<s[i];
    }
    return 0;
}
   