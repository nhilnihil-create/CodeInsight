#include <bits/stdc++.h>
#define f(i,j,k) for(int i=j;i<k;i++)
#define f2(i,j,k) for(int i=j;i>k;i--)
using namespace std;
int main(){
    string s;
    cin>>s;
    while(1){
        s.erase(s.size()-2);
        if(s.substr(0,s.size()/2)==s.substr(s.size()/2)){
            break;
        }
    }
    cout<<s.size()<<endl;
    return 0;
}
