#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    if(a[0] != (a[n-1] + 1) / 2){ cout << "Impossible" << endl; return 0; }

    int current = 0;
    for(int i=a[0]; i<=a[n-1]; i++){
        int count = 0;
        while(a[current] == i){
            count += 1;
            current += 1;
        }

        if(i == a[0]){
            if(a[n-1] % 2 == 0 && count != 1){ cout << "Impossible" << endl; return 0; }
            if(a[n-1] % 2 == 1 && count != 2){ cout << "Impossible" << endl; return 0; }
        }
        else{
            if(count < 2){ cout << "Impossible" << endl; return 0; }
        }
    }
    cout << "Possible" << endl;
    return 0;
}