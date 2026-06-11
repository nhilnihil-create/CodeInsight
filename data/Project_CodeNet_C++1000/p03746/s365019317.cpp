#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100005;
vector<int> S[MAX];
int state[MAX],N;
stack<int> st,st2;

void DFS2(int u){
    for(int i=0;i<N;i++){
        state[i]=0;
    }
    vector<int> T={u+1};
    state[u]=1;
    st.push(u);
    bool flag=true;
    while(flag){
        int a=st.top();
        st.pop();
        for(int i=0;i<S[a].size();i++){
            int b=S[a][i];
            if(!state[b]){
                state[b]=1;
                st.push(b);
                T.push_back(b+1);
                break;
            }
            if(i==S[a].size()-1) flag=false;
        }
    }
    
    vector<int> T2;
    st2.push(u);
    flag=true;
    while(flag){
        int a=st2.top();
        st2.pop();
        for(int i=0;i<S[a].size();i++){
            int b=S[a][i];
            if(!state[b]){
                state[b]=1;
                st2.push(b);
                T2.push_back(b+1);
                break;
            }
            if(i==S[a].size()-1) flag=false;
        }
    }
    
    
    cout<<T.size()+T2.size()<<endl;
    
    reverse(all(T));
    
    for(int i=0;i<T.size();i++){
        if(i) cout<<" ";
        cout<<T[i];
    }
    
    for(int i=0;i<T2.size();i++){
        cout<<" "<<T2[i];
    }
    
    cout<<endl;
    
}

int main(){
    
    int M;cin>>N>>M;
    
    for(int i=0;i<M;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        S[a].push_back(b);
        S[b].push_back(a);
    }
    
    for(int i=0;i<N;i++){
        if(S[i].size()>=2){
            DFS2(i);
            break;
        }
    }
    
    if(N==2) cout<<2<<endl<<1<<" "<<2<<endl;
    
}
