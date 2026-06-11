#include<bits/stdc++.h>;
using namespace std;
//#define LOCAL
typedef long long ll;
#define fastIO ios::sync_with_stdio(0), cin.tie(0)

int main(){
#ifdef LOCAL
     freopen("in.txt", "r", stdin);
     //freopen("out.txt", "w", stdout);
#else
 fastIO;
#endif
//***************************//**************************//******************************

int n,l;
cin>>n>>l;
vector<string> v(n);
for(int i=0;i<n;i++){
    string s;
    cin>>s;
    v.push_back(s);
}
sort(v.begin(),v.end());
for(auto &x:v){
    cout<<x;
}
}

