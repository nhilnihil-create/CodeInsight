#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
    cin.tie(NULL); cout.tie(NULL);
    ios_base:: sync_with_stdio(false);
    string s;cin>>s;
    if(s.size()<4)return cout<<"No" , 0;
    cout<<(s.substr(0,4)=="YAKI"?"Yes":"No");
}



