#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> vec(n);
    int ans;
    ans = 0;
    for(int i=0; i<n; i++){
        cin >> vec[i];
        vec[i];
    }
    for(int i=0; i<n; i++){
        int tmp1 = vec[vec[i]-1];
        int tmp2 = i+1;
        if(tmp1 == tmp2){
            ans++;
        }
    }
    cout << ans/2 << endl;
}

