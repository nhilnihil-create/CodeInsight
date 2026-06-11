#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P =pair<int,int>;

int main() {
    string s;
    cin>>s;
    string c="CODEFESTIVAL2016";
    int misscount=0;
    rep(i,16){
        if(s.at(i)!=c.at(i)){
            misscount+=1;
        }
    }
    cout<<misscount<<endl;
return 0;}
/*
g++ code.cpp
./a.out
*/