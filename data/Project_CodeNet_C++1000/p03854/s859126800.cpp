#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int main(){
    string S(100030,'A');
    cin>>S;
    int t=0,fie[100030]={0};
    fie[0]=1;
    for(int i=1;S[i]!='A';i++){
        if(fie[i-1]){
            if(S.substr(i-1,5)=="dream")fie[i+4]=1;
            if(S.substr(i-1,5)=="erase")fie[i+4]=1;
            if(S.substr(i-1,6)=="eraser")fie[i+5]=1;
            if(S.substr(i-1,7)=="dreamer")fie[i+6]=1;
        }
    }
/*
    for(int i=0;i<20;i++){
        cout<<fie[i];
    }
    puts("");
    for(int i=0;i<20;i++){
        cout<<S[i];
    }
    puts("");
*/
    for(int i=100015;;i--){
        if(S[i]!='A'){
//            cout<<i<<endl;
            if(fie[i]==1)puts("YES");
            else puts("NO");
            break;
        }
    }
    return 0;
}
