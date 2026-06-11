#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
map<P,int> mp;
int n,k,l,x,y;
int fa1[200005],fa2[200005];
int find1(int x){return x==fa1[x]?x:fa1[x]=find1(fa1[x]);}
int find2(int x){return x==fa2[x]?x:fa2[x]=find2(fa2[x]);}

int main(void){
    cin>>n>>k>>l;
    for(int i=1;i<=n;i++){
        fa1[i]=fa2[i]=i;
    }
    for(int i=0;i<k;i++){
        cin>>x>>y;
        x=find1(x),y=find1(y);
        if(x!=y)fa1[y]=x;
    }
    for(int i=0;i<l;i++){
        cin>>x>>y;
        x=find2(x),y=find2(y);
        if(x!=y)fa2[y]=x;
        /*
        for(int i=1;i<=n;i++){
        cout<<fa2[i];
    }
    cout<<" "<<x<<" "<<y<<endl;*/
    }
    for(int i=1;i<=n;i++)fa1[i]=find1(fa1[i]),fa2[i]=find2(fa2[i]);
    for(int i=1;i<=n;i++)mp[P(fa1[i],fa2[i])]++;
    for(int i=1;i<=n;i++)cout<<mp[P(fa1[i],fa2[i])]<<" ";
    cout<<endl;
    
    }
