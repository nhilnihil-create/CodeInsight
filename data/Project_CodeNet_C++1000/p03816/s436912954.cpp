#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;
typedef pair<int, int> P;
int main(){
    int n;
    int a[100010];
    cin >> n;
    for(int i = 0; i < 100010; i++){
        a[i] = 0;
    }
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        //a[i] = temp;
        a[temp]++;
    }
    vector<int> hoge;
    for(int i = 1; i <= 100000;i++){
        if(a[i] > 1){
            for(int j = 0; j < a[i]-1; j++){
                hoge.push_back(i);
            }
        }
    }
    int ans;
    int huga = hoge.size();
    if(huga % 2 == 0){
        ans = n - huga ;
    }
    else{
        ans = n - huga - 1;
    }
    cout << ans << endl;

}