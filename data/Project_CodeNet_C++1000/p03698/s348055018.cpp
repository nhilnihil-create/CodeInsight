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
    string str;
    cin>>str;
    set<char> s;
    for(auto x: str){
        if(s.count(x)){
            cout<<"no";
            return 0;
        }
        s.insert(x);
    }
    cout<<"yes";
}

