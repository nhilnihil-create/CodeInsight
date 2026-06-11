#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int p[100010];
    for(int i = 1; i <= n; i++){
        cin >> p[i];
    }
    int ans = 0;
    bool check = false;
    for(int i = 1; i <= n; i++){
        if(p[i] == i){
            if(check == false){
                ans++;
                check = true;
                continue;
            }
        }
        check = false;
    }
    cout << ans << endl;
    return 0;
}