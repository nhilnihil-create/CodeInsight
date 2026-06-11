#include<bits/stdc++.h>

using namespace std;

int main()
{
    map<char,int>m;
    map<char,int>::iterator itr;
    string s;
    cin>>s;
    int i,n=s.length(),chk=0;

    if(n%2!=0) cout<<"No";
    else{
    for(i=0;i<n;i++){
        m[s[i]]++;
    }
    for(itr=m.begin();itr!=m.end();itr++){
        if(itr->second%2!=0){
                chk=1;
            break;
        }}
   if(chk==0){
        cout<<"Yes";
    }
    else cout<<"No";}
    return 0;
}
