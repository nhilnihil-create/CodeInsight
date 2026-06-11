#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int n;

int main(){
scanf("%d",&n);
for (int x = 0; x<n; x++){
    int t;
    scanf("%d",&t);
    v.push_back(t);
}
sort(v.begin(),v.end(),greater<int>());
v.push_back(0);
for (int x = 0; x<=n; x++){
    if (v[x]<=x){
        int x1 = 1;
        int x2 = 1;
        x1 = v[x-1]-(x-1);

        int y = x;
        if (v[x]==x){
            while (v[y]==v[x] && y!=n){
                y++;
            }
            x2 = y-x+1;
        }

        if (x2%2==1 && x1%2==1){
            printf("Second");
        }
        else{
            printf("First");
        }
        return 0;
    }
}
}
