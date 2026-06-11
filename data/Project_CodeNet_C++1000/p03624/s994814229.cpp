
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
#define ll long long
const int inf = 1000000000;

int main(){
    string s;
    char ans=123;
    
    cin >> s;
    vector<int> a(200);
    rep(i,200){
        a[i]=0;
    }
    

    rep(i,s.size()){
        a[s[i]]++;
    }
    for(char i= 'a';i<='z';i++){
        if(a[i]==0){
            ans=min(ans,i);
        }
    }
    if(ans==123){
        cout << "None" << endl;
    }   
    else{
        cout << ans << endl;
    }
    return 0;
}