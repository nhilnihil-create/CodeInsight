#include <bits/stdc++.h>
#define f(i,j,k) for(int i=j;i<k;i++)
using namespace std;
int main(){
    deque <long long> a;
    string s;
    cin>>s;
    f(i,0,s.size()){
        if(s[i]=='0'){
            a.push_back(0);
        }
        else if(s[i]=='1'){
            a.push_back(1);
        }
        else{
            if(!a.empty()){
                a.pop_back();
            }
        }
    }
    f(i,0,a.size()){
        cout<<a[i];
    }
    cout<<endl;
    return 0;
}