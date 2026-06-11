#include <iostream>
using namespace std;
int main(){
    int n, x, odd=0;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> x;
        if(x%2==1){
            odd++;
        }
    }
    if(odd%2==0){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}