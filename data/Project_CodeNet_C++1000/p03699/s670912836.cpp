#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n, s = 0, min, k, ans = 0;
    
    cin >> n;
    vector<int> ve(n);
    for(int i = 0; i < n; i++){
        cin >> ve[i];
        s += ve[i];
    }

    if(s % 10 != 0){
        cout << s << endl;
    }else{
        for(int i = 0; i < n; i++){
            min = i;
            for(int j = i + 1; j < n; j++) if(ve[min] > ve[j]) min = j;
            k = ve[i];
            ve[i] = ve[min];
            ve[min] = k;
        }
        
        for(int i : ve){
            if(i % 10 != 0){
                ans = s - i;
                break;
            }
        }
        cout << ans << endl;
    }
}