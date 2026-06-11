#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second&&a.first<b.first);
}

void solve(){
    int k,s;
    cin>>k>>s;
    int cn=0;
    for(int i=0;i<=k;i++){
        for(int j=0;j<=k;j++){
            int m=s-i-j;
            if(m>=0&&m<=k)
                cn++;

        }
    }
    cout<<cn;
}


int main(){
    /*int t;
    cin>>t;
    while(t--)*/
        solve();


    return 0;
}
































































//1-(3+5-2+(3+19-(3-1-4+(9-4-(4-(1+(3)-2)-5)+8-(3-5)-1)-4)-5)-4+3-9)-4-(3+2-5)-10


















