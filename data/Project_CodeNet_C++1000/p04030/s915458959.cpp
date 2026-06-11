#include<bits/stdc++.h>
using namespace std;

int main(){
    string S;
    cin>>S;

    string ans;
    for(auto s : S){
        if(s=='0'){
            ans.push_back('0');
        }else if(s=='1'){
            ans.push_back('1');            
        }else if(s=='B' && ans.size()>0){
            ans.pop_back();
        }
    }
    cout<< ans <<endl;
    return 0;
}