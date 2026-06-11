#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iomanip>
#include<stack>
using namespace std;
#define rep(i,s,t) for(int i=s;i<=t;i++)
#define mem(a,s) memset(a,s,sizeof(a))
stack<char> st;
char c;
int len;
int main(){
    //freopen("in.txt","r",stdin);
    while((c = getchar())!=EOF){
        if(c=='S')
            st.push(c);
        if(c=='T'){
            if(st.empty()||st.top()=='T'){
                len++;
                continue;
            }
            st.pop();
        }
    }
    cout<<len + st.size();
    return 0;
}