#include <bits/stdc++.h>
#include <math.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    string p="CODEFESTIVAL2016";
    int count=0;
    for(int i=0;i<s.size();i++){
        
        if(s.at(i)!=p.at(i)){
            count++;
        }
    }

    cout<<count<<endl;
    return 0;
}