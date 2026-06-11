#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mxn= 5e5+5;
#define mod 1000000007
#define endl '\n'
void rishabh(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int main(){
    rishabh();
    string str;
    set<char>s;
    cin>>str;
    for(auto x : str){
        s.insert(x);
    }
    for(char i='a';i<='z';i++){
        if(!s.count(i)){
            cout<<i;
            return 0;
        }
    }
    cout<<"None";
}

