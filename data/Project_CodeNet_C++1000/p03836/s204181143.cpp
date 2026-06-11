#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second&&a.first<b.first);
}

void solve(){
    int sx,sy,tx,ty;
    cin>>sx>>sy>>tx>>ty;
    int diffx=tx-sx,diffy=ty-sy;
    for(int i=0;i<diffy;i++){
        cout<<"U";
    }
    for(int i=0;i<diffx;i++)
        cout<<"R";
    for(int i=0;i<diffy;i++)
        cout<<"D";
    for(int i=0;i<diffx;i++)
        cout<<"L";
    cout<<"L";
    for(int i=0;i<=diffy;i++)
        cout<<"U";
    for(int i=0;i<=diffx;i++)
        cout<<"R";
    cout<<"DR";
    for(int i=0;i<=diffy;i++)
        cout<<"D";
    for(int i=0;i<=diffx;i++)
        cout<<"L";
    cout<<"U";
}


int main(){
    /*int t;
    cin>>t;
    while(t--)*/
        solve();


    return 0;
}
































































//1-(3+5-2+(3+19-(3-1-4+(9-4-(4-(1+(3)-2)-5)+8-(3-5)-1)-4)-5)-4+3-9)-4-(3+2-5)-10


















