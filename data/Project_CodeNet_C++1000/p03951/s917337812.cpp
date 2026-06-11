#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll mxn= 2e4+5;
// check for forloop
// intialize variable
// overflow
// go for easy solution
#define mod 1000000007
ll INF = 1000000000000000005LL;
#define endl '\n'
void rishabh(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
// 1
// 5
// 0 1 0 2 0
int main(){
    rishabh();
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    deque<char> temp;
    set<deque<char>> st;
    for(auto x: t){
        temp.push_back(x);
        st.insert(temp);
    }
    temp.clear();
    int ans=0;
    for(int i=n-1;i>=0;i--){
        temp.push_front(s[i]);
        if(st.count(temp))ans=n-i;
    }
    cout<<2*n-ans;
}