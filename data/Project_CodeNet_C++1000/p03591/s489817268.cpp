#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    string str;
    while(cin>>str){
        string st="YAKI";
        int flag=1;
        for(int i=0;i<4;i++){
            if(str[i]!=st[i]){
                flag=0;
                break;
            }
        }
        cout<<(flag?"Yes":"No")<<endl;
    }
    return 0;
}
