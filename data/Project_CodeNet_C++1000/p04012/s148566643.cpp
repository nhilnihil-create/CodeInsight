#include <bits/stdc++.h>
using namespace std;

int main(void){
    vector<int>A(26,0);
    string w;cin>>w;
    for(int i=0;i<w.size();i++){
        A[(int)w[i]-97]++;
    }
    for(int i=0;i<26;i++){
        if(A[i]%2==1){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}