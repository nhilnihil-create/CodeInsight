#include <bits/stdc++.h>
using namespace std;

vector<int> winlist[100005];

int func(int node){
    if (winlist[node].size()==0){
        return 0;
    }
    else{
        vector<int> v;
        for (int x : winlist[node]){
            v.push_back(func(x));
        }
        sort(v.begin(),v.end());
        int ans = 0;
        for (int x = v.size(); x>0; x--){
            ans = max(ans,x+v[v.size()-x]);
        }
        return ans;
    }
}

int main(){
int n;
scanf("%d",&n);
for (int x = 2; x<=n; x++){
    int a;
    scanf("%d",&a);
    winlist[a].push_back(x);
}
printf("%d",func(1));
}
