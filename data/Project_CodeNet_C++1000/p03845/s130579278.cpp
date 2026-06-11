#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second&&a.first<b.first);
}

void solve(){
    int n,m,sum=0;
    cin>>n;
    vector<int>t(n);
    for(int i=0;i<n;i++){
        cin>>t[i];
        sum+=t[i];
    }
    cin>>m;
    vector<int>p(m),x(m);
    for(int i=0;i<m;i++){
        cin>>p[i]>>x[i];
        cout<<sum-t[p[i]-1]+x[i]<<endl;
    }


}


int main(){
    /*int t;
    cin>>t;
    while(t--)*/
        solve();


    return 0;
}
































































//1-(3+5-2+(3+19-(3-1-4+(9-4-(4-(1+(3)-2)-5)+8-(3-5)-1)-4)-5)-4+3-9)-4-(3+2-5)-10


















