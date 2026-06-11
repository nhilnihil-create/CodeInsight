#include <bits/stdc++.h>
using namespace std;



int main(){
    int N;
    cin>>N;
    int kisu=0,gusu=0;
    vector<long> data(N);
    for(int i=0;i<N;i++){
        cin>>data[i];
        if(data[i]%2==0)gusu++;
        else kisu++;
    }

    bool ans=true;

    if(kisu%2!=0)ans=false;

    if(ans)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;


    }

    

