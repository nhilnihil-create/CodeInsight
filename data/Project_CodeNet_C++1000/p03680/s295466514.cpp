#include<bits/stdc++.h>
using namespace std;

#define Bye return 0
#define ll long long
const int MAX = 1e5+1;
int a[MAX];
bool b[MAX];

int search(int i, int sum){
    if(b[i] == true) return -1;
    if(i == 2) return sum;
    
    b[i] = true;

    return search(a[i], sum + 1);
}

void solve(){
    int n; cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    memset(b, false, sizeof b);
    int res = search(1, 0);
    cout<<res<<endl;
}

int main(){
    solve();
    Bye;
}