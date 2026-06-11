#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main(){
        int n,x=0,max=0;   cin>>n;
        string s;  cin>>s;
        rep(i, n){
                if(s[i]=='I')
                   x++;
                if(max<x)
                   max=x;
                else if(s[i]=='D')
                        x--;



        }
        cout<<max<<endl;
}
