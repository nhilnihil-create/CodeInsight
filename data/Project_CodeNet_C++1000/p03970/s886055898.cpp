#include <bits/stdc++.h>
using namespace std;
struct point{double x;double y;};
int i,j,k,count1=0,count2=0;

int main(void){
    int ans=0;
    string s,t="CODEFESTIVAL2016";
    cin>>s;
    for(i=0;i<s.length();i++){
        if(s[i]!=t[i])ans++;
    }
    cout<<ans<<endl;
}