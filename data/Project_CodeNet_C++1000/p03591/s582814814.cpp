#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P =pair<int,int>;

int main() {
    string S;
    cin>>S;
    if(S.size()>=4){
        if(S.at(0)=='Y'){
            if(S.at(1)=='A'){
                if(S.at(2)=='K'){
                    if(S.at(3)=='I'){
                        cout<<"Yes"<<endl;
                            return 0;
                    }
                }
            }    
        }
    }else{
        cout<<"No"<<endl;
        return 0;
    }
cout<<"No"<<endl;
return 0;}
/*
g++ code.cpp
./a.out
*/