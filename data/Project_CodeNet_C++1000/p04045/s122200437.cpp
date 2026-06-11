#include<iostream>
using namespace std;
bool In[15];
bool Check(int x) {
    while(x) {
        if(In[x%10]) return false;
        x /= 10;
    }
    return true;
}
int main() {
    int n,k,x;
    cin >> n >> k;
    for(int i = 1; i <= k; ++i)
        cin >> x, In[x] = true;
    for(int i = n;; ++i) {
        if(Check(i)) {
            printf("%d\n",i);
            break;
        }
    }
return 0;
}