#include<bits/stdc++.h>
using namespace std;

int main(){
     string s;
cin>>s;
        map<char, int> m;
        for(char x: s){
            m[x]++;
        }
        for(auto x: m) if(x.second%2!=0) {cout<<"No"<<endl; return 0;}
        cout<<"Yes"<<endl;

}
