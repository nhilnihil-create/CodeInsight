#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main(){
    IOS;
    int n ,a ,b;
    cin >>  n >> a >>b;
    string s;
    cin >> s;
    int count = 0;
    int bcount = 0;
    for(int i=0; i<n; i++){
        if(s[i]=='c'){
            cout << "No" <<endl;
        }else if(count < a+b && s[i]=='a'){
            cout << "Yes" <<endl;
            count++;
        }else if(count < a+b && s[i]=='b' && bcount<b){
            cout << "Yes" <<endl;
            count++;
            bcount++;
        }else{
            cout << "No" <<endl;
        }
    }
}