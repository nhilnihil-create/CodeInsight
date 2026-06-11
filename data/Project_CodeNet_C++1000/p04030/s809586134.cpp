#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#define ll long long int

using namespace std;

string s;
stack <string> stk;

int main()
{
    ///freopen("INA.txt","r",stdin);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>> s;
    for(int i=0;i<s.length();i++){
        if(s[i]=='0'){ stk.push("0"); }
        else if(s[i]=='1'){ stk.push("1"); }
        else{
            if(!stk.empty()){
                stk.pop();
            }
        }
    }
    string ans="";
    while(!stk.empty()){
        string c = stk.top();
        ans += c;
        stk.pop();
    }
    reverse(ans.begin(),ans.end());
    cout<< ans << endl;
    return 0;
}

