# include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pii pair<int,int>
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin>>s;
    stack<char>st;
    int ans=s.size();
    for(auto isi:s){
        if(isi=='S') {
            st.push('S');

        }
        else {
            if(st.empty()==false){
                st.pop();
                ans-=2;
            }
        }
    }   
    cout<<ans<<endl;
}