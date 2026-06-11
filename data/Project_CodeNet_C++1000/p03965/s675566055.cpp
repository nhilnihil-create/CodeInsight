#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
const int INF=1e9;

int main(){
    string s;
    cin>>s;
    int cnt=0;
    for(char c:s){
        if(c=='p')cnt++;
    }
    cout<<(int)s.size()/2-cnt<<endl;
}
