#include<bits/stdc++.h>
using namespace std;
int main(){
    int x=0;
    int max=0;
    int n;
    cin>>n;
    vector<char> s(n);
    for(int i=0;i<n;i++){
        cin>>s.at(i);
    }
    for(int i=0;i<n;i++){
        if(s.at(i)=='I'){
            x++;
            if(x>max) max=x;
        }
        if(s.at(i)=='D'){
            x--;
            if(x>max) max=x;
        }
    }
    cout<<max<<endl;
}