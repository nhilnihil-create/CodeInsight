#include <iostream>

using namespace std;

int main(){
    int i,n,a[100010],j;
    long long ans;
    cin >> n;
    for(i=0;i<n;i++){
        cin >> a[i];
    }
    ans += a[0]-1;
    j = 2;
    for(i=1;i<n;i++){
        ans += (a[i]-1)/j;
        if(a[i]==j){
            j++;
        }
    }
    cout << ans << endl;
}