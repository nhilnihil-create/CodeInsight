#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int main(){
    string s;
    cin>>s;

    int n=s.size();
    stack<char> st;
    int cnt=0;
    rep(i,n){
        if(s[i]=='S') st.push('S');
        else{
            if(!st.empty()){
                cnt++;
                st.pop();
            }
        }
    }

    cout<<n-2*cnt<<endl;
}
    


