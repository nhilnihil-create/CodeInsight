#include<bits/stdc++.h>;
using namespace std;
//#define LOCAL
typedef long long ll;
#define fastIO ios::sync_with_stdio(0), cin.tie(0)
#define endl '\n'

int main(){
#ifdef LOCAL
     freopen("in.txt", "r", stdin);
     //freopen("out.txt", "w", stdout);
#else
 fastIO;
#endif
//***************************//**************************//******************************

string s,ans;
cin>>s;
for(auto &x:s){
    if(x=='B' && !ans.empty()){
        ans.pop_back();
    }else if(x=='1' || x=='0'){
        ans.push_back(x);
    }
}
cout<<ans;
}

