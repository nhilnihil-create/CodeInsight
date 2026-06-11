//Signboard
#include <bits/stdc++.h>
using namespace std;

int main(){
    string S;
    cin>>S;
    string sample="CODEFESTIVAL2016";
    int count=0;
    for(int i=0;i<sample.size();i++){
        if(sample.at(i)!=S.at(i))count++;
    }
    cout<<count<<endl;
    return 0;
}