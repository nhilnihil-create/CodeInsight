#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    long long int ans = 1001001001001;
    for(int bit = 0; bit < (1 << n); bit++){
        long long int coans = 0;
        int colornum = 0;
        int height = 0;
        for(int i = 0; i < n; i++){
            if(bit & (1 << i)){
                colornum++;
                if(a[i] > height){
                    height = a[i];
                }else{
                    coans += height-a[i]+1;
                    height++;
                }
            }else{
                if(height < a[i]) height = a[i];
            }
        }
        
        if(colornum >= k && coans < ans) ans = coans;
    }
    cout << ans << endl;
    return 0;
}