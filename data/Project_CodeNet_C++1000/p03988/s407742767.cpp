#include <cstdio>
#include <algorithm>
using namespace std;
int n;
int arr[105];
int nums[105];
int main(){
    scanf("%d",&n);
    int best=-1;
    for (int x=0;x<n;x++){
        scanf("%d",&arr[x]);
        best=max(best,arr[x]);
        nums[arr[x]]++;
    }
    
    if (best==1 && n>2){
        printf("Impossible");
        return 0;
    }
    
    int temp;
    for (int x=0;x<=best;x++){
        temp=max(best-x,x);
        if (nums[temp]==0){
            printf("Impossible");
            return 0;
        }
        nums[temp]--;
    }
    
    for (int x=1;x<=((best+1)>>1);x++){
        if (nums[x]){
            printf("Impossible");
            return 0;
        }
    }
            
    printf("Possible");
}