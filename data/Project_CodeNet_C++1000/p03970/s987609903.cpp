#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    string str1,str2;
    cin>>str1;
    str2="CODEFESTIVAL2016";
    int ans=0;
    for(int i=0;i<16;i++){
        if(str1[i]!=str2[i])ans++;
    }
    cout<<ans<<endl;
    return 0;
}