#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int MAXN  = 1e5+5;
int pref[MAXN];
int pref2[MAXN];
int check(int x,int y){
    if(x==0){
        return pref[y]%3;
    }
    return (pref[y]-pref[x-1])%3;
}

int check2(int x,int y){
    if(x==0){
        return pref2[y]%3;
    }
    return (pref2[y]-pref2[x-1])%3;
}
int main(){
    string s,t;
    cin>>s>>t;
    int q;
    cin>>q;
    if(s[0] == 'A'){
        pref[0] = 1;
    }else{
        pref[0] = 2;
    }
    for(int i=1;i<s.length();i++){
        if(s[i] == 'A'){
            pref[i] = pref[i-1]+1;
        }else{
            pref[i]  =pref[i-1]+2;
        }
    }
    if(t[0] == 'A'){
        pref2[0] = 1;
    }else{
        pref2[0] = 2;
    }
    for(int i=1;i<t.length();i++){
        if(t[i] == 'A'){
            pref2[i] = pref2[i-1]+1;
        }else{
            pref2[i] = pref2[i-1]+2;
        }
        //cout<<pref2[i]<<endl;
    }
    while(q--){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        a--;
        b--;
        c--;
        d--;
        int val1 = check(a,b);
        int val2 = check2(c,d);
       
        if(val1 == val2){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
}