#include <bits/stdc++.h>
using namespace std;
multiset<int> ms;
bool del(int x){
    //printf("remove %d ",x);
    auto it = ms.find(x);
    if (it == ms.end()) return false;
    else ms.erase(it);
    return true;
}
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    int k = 0;
    for (int i = 0; i < n; i++){
        scanf("%d",&a[i]);
        ms.insert(a[i]);
        k = max(k,a[i]);
    }
    int half = (k+1)/2;
    for (int i = half; i <= k; i++){
        if (i == half && (k & 1) == 0){
            if (!del(i)){
                printf("Impossible");
                return 0;
            }
        }
        else{
            if (!del(i)){
                printf("Impossible");
                return 0;
            }
            if (!del(i)){
                printf("Impossible");
                return 0;
            }
        }
    }
    for (auto x : ms){
        if (x < half+1){
            printf("Impossible");
            return 0;
        }
    }
    printf("Possible");

}
