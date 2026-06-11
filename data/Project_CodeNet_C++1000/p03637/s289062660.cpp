#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int multof4 = 0;
    int multof2 = 0;
    int other = 0;
    for(int i = 0; i < n; i++){
        if(a[i] % 4 == 0) multof4++;
        else if(a[i] % 2 == 0) multof2++;
        else other++;
    }

    if(multof2 == 0){
        if(multof4 >= n/2) cout << "Yes" << endl;
        else cout << "No" << endl;
    }else{
        if(multof4 >= (n-multof2+1)/2) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}