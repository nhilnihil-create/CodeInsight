#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
using namespace std;
typedef long long ll;
int main(){
   #ifndef ONLINE_JUDGE 
      FILE_READ_IN 
      FILE_READ_OUT 
   #endif
    string s; cin>>s;
    deque<char> st;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='B'&&!st.empty())
        {
            st.pop_back();
        }
        else if(s[i]!='B')
            st.push_back(s[i]);
    }

    while(!st.empty())
    {
        cout<<st.front();
        st.pop_front();
    }
   return 0;
}