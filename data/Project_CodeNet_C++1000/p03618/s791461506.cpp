#include <bits/stdc++.h>
using namespace std;
const int N = 200000 + 10;
char s[N];
int a[N];
int main(){
    scanf("%s",s);
    int n = strlen(s);
    long long ans = 0;
    for(int i=n-1;i>=0;i--){
        ans += n-1-i-a[s[i]-'a'];
        a[s[i]-'a']++;
    }
    printf("%lld\n",ans+1);
}
