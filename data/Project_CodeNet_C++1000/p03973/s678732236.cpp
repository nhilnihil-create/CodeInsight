#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; cin >> n;
    vector<int> a(n, 0);

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int min_p = 1;
    long long int counter = 0;

    for(int i = 0; i < n; i++){
        
        if(a[i] < min_p) continue;
        else if(a[i] == min_p){
            min_p += 1;
            continue;
        }else{
            counter += (a[i]-1) / min_p;
            if(i == 0) min_p = 2;
        }
    }

    cout << counter << endl;
    return 0;
}