#include <bits/stdc++.h>
using namespace std;

int n,m;
int arr[100005];
vector<int> ans;

int main(){
scanf("%d%d",&n,&m);
int numodd = 0;

for (int x = 0; x<m; x++){
    scanf("%d",&arr[x]);
    if (arr[x]%2==1) numodd++;
    if (numodd>2) {
        printf("Impossible");
        return 0;
    }
}
if (m==1){
    printf("%d\n",arr[0]);
    if (arr[0]!=1){
        printf("2\n%d 1",arr[0]-1);
    }
    else printf("1\n1");
    return 0;
}
for (int x = 0; x<n; x++){
    if (arr[x]%2==1 && arr[0]%2!=1) swap(arr[0],arr[x]);
    if (arr[x]%2==1 && arr[m-1]%2!=1) swap(arr[x],arr[m-1]);
}
if (arr[0]!=1) ans.push_back(arr[0]-1);
for (int x = 1; x<m-1; x++){
    ans.push_back(arr[x]);
}
ans.push_back(arr[m-1]+1);
for (int x = 0; x<m; x++){
    printf("%d ",arr[x]);
}
printf("\n%d\n",ans.size());
for (auto x : ans){
    printf("%d ",x);
}
}
