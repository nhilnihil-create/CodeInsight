#include<bits/stdc++.h>
using namespace std;
 
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    string s1,s2;cin>>s1>>s2;
    int n1,n2;
    n1 = s1.size();
    n2 = s2.size();
    if(n1>n2){
        cout<<"GREATER"<<endl;
        return 0;
    }
    if(n1<n2){
        cout<<"LESS"<<endl;
        return 0;
    }
    
    rep(i,n1){
        if(s1[i]>s2[i]){
            cout<<"GREATER"<<endl;
            return 0;
        }
        if(s1[i]<s2[i]){
        cout<<"LESS"<<endl;
        return 0;
    }
    }
    cout<<"EQUAL"<<endl;
	return 0;
}