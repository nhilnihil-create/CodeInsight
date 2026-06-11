#include <bits/stdc++.h>
using namespace std;

//考察寄りの問題。ちょっと難しかった。
//2(mod4)がある場合とない場合で場合分けする。
//2(mod4)がある場合はそれらを全部ひとまとめにする。


int main(){
    int n;
    cin >> n;
    int a[110000];
    int fourCount = 0, twoCount = 0, oddCount = 0;
    for(int i=0; i<n; i++){
        cin >> a[i];
        if(a[i] % 4 == 0){
            fourCount++;
        }else if(a[i] % 4 == 2){
            twoCount++;
        }else{
            oddCount++;
        }
    }
    string ans = "Yes";
    if(twoCount == 0  &&  fourCount >= n/2){
        cout << ans << endl;
        return 0;
    }
    vector<int> vec;
    for(int i=0; i<twoCount; i++){
        vec.push_back(2);
    }
    for(int i=0; i<n-twoCount; i++){
        if(fourCount > 0){
            vec.push_back(4);
            fourCount--;
        }else{
            vec.push_back(1);
            oddCount--;
        }
        i++;
        if(i==n-twoCount) break;
        if(oddCount > 0){
            vec.push_back(1);
            oddCount--;
        }else{
            vec.push_back(4);
            fourCount--;
        }
    }

    // for(auto itr = vec.begin(); itr != vec.end()-1; itr++) {
    //     if(*itr * *(itr+1) % 4 != 0){
    //         ans = "No";
    //     }
    // }
    for(int i=0; i<vec.size()-1; i++) {
        if(vec[i] * vec[i+1] % 4 != 0){
            ans = "No";
        }
    }
    cout << ans << endl;
    return 0;
}