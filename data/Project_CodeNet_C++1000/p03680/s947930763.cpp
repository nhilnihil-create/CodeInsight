#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        a[i]--;
    }
    set<int> st;
    int ans=0;
    int pos=0;
    bool ok=1;
    st.insert(pos);
    while(true){
        ans++;
        if(a[pos]==1) break;
        if(st.count(a[pos])){
            ok=0;
            break;
        }
        st.insert(a[pos]);
        pos=a[pos];
    }
    cout<<(ok?ans:-1)<<endl;
}