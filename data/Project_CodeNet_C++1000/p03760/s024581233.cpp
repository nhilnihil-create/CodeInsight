#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int main(){
    string S1,S2;
    cin>>S1>>S2;
    for(int i=0;i<S1.size();i++){
        cout<<S1[i];
        if(i==S1.size()-1&&S2.size()<S1.size()){
            break;
        }
        cout<<S2[i];
    }
    cout<<endl;
    return 0;
}
