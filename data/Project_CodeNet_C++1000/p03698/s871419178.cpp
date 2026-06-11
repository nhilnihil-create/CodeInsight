#include <bits/stdc++.h>

using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long int
#define INF 1000000007
// cin.eof() 入力個数の問題
int main(){
string S;
cin>>S;
map<char,bool> m;
rep(i,S.size()){
    if(m[S[i]]){
        cout<<"no"<<endl;
        return 0;
    }else{
        m[S[i]]=true;
    }
}

cout<<"yes"<<endl;
  return 0;
}
