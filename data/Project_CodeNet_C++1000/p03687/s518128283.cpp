#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<n;i++)
#include <bits/stdc++.h>
#include <numeric>
using namespace std;
typedef long long ll;
const int mod= 1e+9+7;

bool judge(string t,char z){
    for(int i=0;i<t.size();i++){
        if(t[i]!=z)return false;
    }
    return true;
}

int main() {
    string s; cin>>s;
    int mn =100000;
    for(char c='a';c<='z';c++){
        string t=s;
        for(int i=0;;i++){
            if(judge(t,c)){
                mn = min(mn,i);
                break;
            }
        string nt;
        for(int j=0;j<t.size()-1;j++){
            if(t[j]==c||t[j+1]==c)nt+=c;
            else nt+=t[j];
        }
        t=nt;
        }

    }
    cout<<mn<<endl;

}

