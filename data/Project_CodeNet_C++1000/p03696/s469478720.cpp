#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int left=0,right=0,x=0;
    for(int i=0;i<n;i++){
        if(s[i]==')')x++;
        else x--;
        left=max(left,x);
    }
    x=0;
    for(int i=n-1;i>=0;i--){
        if(s[i]=='(')x++;
        else x--;
        right=max(right,x);
    }
    for(int i=0;i<left;i++)cout<<'(';
    cout<<s;
    for(int i=0;i<right;i++)cout<<')';
    cout<<endl;
    return 0;
}