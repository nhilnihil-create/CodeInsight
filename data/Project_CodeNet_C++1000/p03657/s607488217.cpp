//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
const int mod= 1e+9+7;

int main(){
    int a,b; cin>>a>>b;
    if(a%3==0||b%3==0||(a+b)%3==0){
        cout<<"Possible"<<endl;
    }
    else cout<<"Impossible"<<endl;
}



