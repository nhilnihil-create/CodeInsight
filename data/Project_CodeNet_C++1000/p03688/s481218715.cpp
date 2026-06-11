#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
const int N=100005;
int n,tot,s,a[N];
set<int> st;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        st.insert(a[i]);
    }
    sort(a+1,a+n+1);
    if(st.size()>2||a[n]-a[1]>1){
        puts("No");
        return 0;
    }else if(a[n]-a[1]==0){
        if(a[n]==n-1){
            puts("Yes");
        }else if(a[n]>n-1){
            puts("No");
        }else if(a[n]*2<=n){
            puts("Yes");
        }else{
            puts("No");
        }
        return 0;
    }
    for(int i=1;i<=n;i++){
        if(a[i]==a[1]){
            tot++;
        }
    }
    s=a[1]-tot+1;
    if(s<1){
        puts("No");
    }else if(s*2<=n-tot){
        puts("Yes");
    }else{
        puts("No");
    }
    return 0;
}