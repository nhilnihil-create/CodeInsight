#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
    string s;
    cin>>s;
    vector<char> ans(0);
    for(int i=0; i<s.size(); i++){
        if(s.at(i)=='1'){
            ans.push_back('1');
        }else if(s.at(i)=='0'){
            ans.push_back('0');
        }else if(s.at(i)=='B'){
            if(ans.size()>=1){
                ans.pop_back();
            }
        }
    }
    for(auto v:ans){
        cout<<v;
    }
    cout<<endl;
}
