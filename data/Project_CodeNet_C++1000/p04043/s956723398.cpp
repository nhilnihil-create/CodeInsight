#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
 
int main() {
    vector<int> v;
    int a,b,c;
    cin>>a>>b>>c;
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    sort(v.begin(),v.end());
    if(v[0]==5 && v[1]==5 && v[2]==7){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}