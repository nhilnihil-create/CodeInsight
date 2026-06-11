#include <bits/stdc++.h>
#define rep(i,N) for(int i=0;i<N;i++)
#define rep2(i,N) for(int i=1;i<=N;i++)
using namespace std;
long long  INF=1000000000000000000;
long long mod=1000000007;
using namespace std;


int main(){

string s;
cin>>s;
long long k;
cin>>k;

for(int i=0;i<s.size()-1;i++){

    if(s[i]=='a')continue;
    if(26-(s[i]-'a')<=k){
        k-=26-(s[i]-'a');
        s[i]='a';
    }
}
k%=26;
s[s.size()-1]='a'+((s[s.size()-1]-'a')+k)%26;

rep(i,s.size()){
    cout<<s[i];
}


return 0;

}
/*
xyz
4

aya

a
25

z

codefestival
100

aaaafeaaivap
*/
