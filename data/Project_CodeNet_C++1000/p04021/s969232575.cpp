#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
struct node{
    int val;
    int pos;
}a[200010];
bool cmp(node a, node b){
    return (a.val < b.val);
}
int n,cnt;
int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>a[i].val;
        a[i].pos = i;
    }
    sort(a+1, a+n+1, cmp);
    for(int i=1; i<=n; i++){
        if (a[i].pos % 2 != i % 2){
            ++cnt;
        }
    }
    cout<<cnt/2<<endl;
    return 0;
    // position difference(? 
    /*
    1 3 5 4 2
    p = 1 2 3 4 5
    if (pos diff % 2 is changed) then adjacent swap=true to make it become (x+1)%2
    ans/2 as one swap affect 2
    */
}