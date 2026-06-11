#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    int cnt = 1, p = 1;
    while(cnt<n){
        p = a[p-1];
        if(p==2){
            break;
        }
        cnt++;
    }
    if(p==2){
        cout << cnt << endl;
    }else{
        cout << -1 << endl;
    }
    return 0;
}