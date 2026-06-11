#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=2e3+5;
int a[N],b[N],n,m;
vector<int>evens,arr;
int odd1,odd2;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d",&a[i]);
        if(a[i]%2==0){
            evens.pb(a[i]);
        }
        else{
            if(odd1==0){
                odd1=a[i];
            }
            else if(odd2==0){
                odd2=a[i];
            }
            else{
                printf("Impossible\n");
                return 0;
            }
        }
    }
    if(m==1){
        if(a[1]==1){
            printf("1\n");
            printf("1\n");
            printf("1\n");
            return 0;
        }
        printf("%d\n",a[1]);
        printf("2\n");
        printf("%d %d\n",a[1]-1,1);
        return 0;
    }
    if(odd1){
        arr.pb(odd1);
    }
    for(auto&x:evens){
        arr.pb(x);
    }
    if(odd2){
        arr.pb(odd2);
    }
    for(auto&x:arr){
        printf("%d ",x);
    }
    printf("\n");
    arr[0]--;
    arr[arr.size()-1]++;
    if(arr[0]<=0){
        arr.erase(arr.begin());
    }
    printf("%d\n",arr.size());
    for(auto&x:arr){
        printf("%d ",x);
    }
    printf("\n");
    return 0;
}
