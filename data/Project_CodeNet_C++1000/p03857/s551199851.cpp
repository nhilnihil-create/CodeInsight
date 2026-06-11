#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
int n,k,l,dsu1[200010],dsu2[200010],x,y;
map< pair<int, int>, int> mp;
int find1(int s){
    if (s == dsu1[s]) return s;
    else return (dsu1[s] = find1(dsu1[s]));
}
int find2(int s){
    if (s == dsu2[s]) return s;
    else return (dsu2[s] = find2(dsu2[s]));
}
int main(){
    cin>>n>>k>>l;
    for(int i=1; i<=n; i++){
        dsu1[i] = i;
        dsu2[i] = i;
    }
    for(int i=1; i<=k; i++){
        cin>>x>>y;
        dsu1[find1(x)] = find1(y);
    }
    for(int i=1; i<=l; i++){
        cin>>x>>y;
        dsu2[find2(x)] = find2(y);
    } 
    for(int i=1; i<=n; i++){
        mp[make_pair(find1(i),find2(i))]++; 
    }
    for(int i=1; i<n; i++){
        cout<<mp[make_pair(find1(i), find2(i))]<<' ';
    }
    cout<<mp[make_pair(find1(n), find2(n))]<<endl;;
    return 0;
}