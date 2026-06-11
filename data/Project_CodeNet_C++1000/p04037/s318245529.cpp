#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 11;
int n, a[N];
int main(){
    //freopen("agc002e.in", "r", stdin);
    cin>>n;
    for(int i = 1;i <= n; i++){
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + 1 + n, greater<int>());
    for(int i = 1;i <= n; i++){
        if(a[i+1] < i + 1){
            int j = i;
            while(a[j+1] == i && j < n)j++;
            int ans = ((a[i] - i) & 1) | ((j - i) & 1);
            //printf("i=%d j=%d\n", i, j);
            puts(ans == 1 ? "First" : "Second");
            return 0;
        }
    }
    return 0;
}
