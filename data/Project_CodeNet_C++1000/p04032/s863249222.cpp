#include<bits/stdc++.h>
#define FILEIN freopen("input.txt", "r", stdin)
using namespace std;

#define ll long long
#define endl "\n"

const ll INF = 1e9;

int main(){
    // FILEIN;
    string s;
    cin>>s;
    for(int i = 0; i<s.length(); i++){
        if(s[i] == s[i+1]){
            cout<<i+1<<" "<<i+2<<endl;
            return 0;
        }
        if((i + 2 < s.length()) && s[i] == s[i + 2]){
            cout<<i + 1<<" "<<i + 3<<endl;
            return 0;
        }
    }
    cout<<"-1 -1"<<endl;
}