#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
    cin>>s;
    int c=s.size();
    if(c%2!=0){
        printf("No");
        return 0;
    }
    for(int i=0;i<c/2;i++){
        short t=abs(s[i]-s[c-i-1]);
        if(t!=1&&t!=2){ 
            printf("No\n"); 
            return 0;
        }
    }
    printf("Yes\n"); 
    return 0;
}