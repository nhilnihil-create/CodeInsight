#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

int main(){
    // 制約見て！！！デカかったらlong longにすること！
    int n,a,b,acnt=0,bcnt=0;
    cin >> n >> a>>b;
    string s;
    cin >> s;
    
    int len = s.size();
    rep(i,len){
        if(s[i]=='a'){
            if(acnt+bcnt < a+b){
                acnt++;
                cout<<"Yes"<<endl;
            }else{
                cout<<"No"<<endl;
            }
        }else if(s[i]=='b'){
            if(bcnt+acnt < a+b && bcnt < b){
                bcnt++;
                cout << "Yes" << endl;
            }else{
                cout<<"No"<<endl;
            }
        }else{
            cout<<"No"<<endl;
        }
    }

}