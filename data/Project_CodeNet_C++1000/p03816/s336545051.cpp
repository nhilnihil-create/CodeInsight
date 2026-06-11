#include<bits/stdc++.h>
using namespace std;


set<int>st;
int main()
{
    int n;cin>>n;
    auto it=st.begin();
    for(int i=0;i<n;i++){
        int a;cin>>a;
        it=st.insert(it,a);
    }
//    for(it=st.begin();it!=st.end();it++)
//        cout<<*it<<" ";
    int ans=st.size();
    if(ans%2==0)ans--;
    cout<<ans<<endl;
}
