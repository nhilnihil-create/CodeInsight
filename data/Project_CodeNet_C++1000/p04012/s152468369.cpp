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

string s;
cin>>s;
map<char,int> m;
for(int i=0;i<s.size();i++){
    m[s[i]]++;
}
bool flag=1;
for(auto &x:m){
 if(x.second&1){
    flag=0;
    break;
 }
}
if(flag){
    cout<<"Yes"<<endl;
}else{
    cout<<"No"<<endl;
}
}

