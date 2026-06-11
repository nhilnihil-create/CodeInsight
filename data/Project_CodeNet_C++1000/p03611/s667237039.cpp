#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<map>
using namespace std;
int main() {
    int N;
    cin >> N;
    int a[100010];
    int amin[100010];
    int amax[100010];
    vector<int> x(100010, 0);
    int X = 0;
    int countx = 0;
    for(int i = 0; i < N; i++) {
        cin >> a[i]; 
        amin[i] = a[i] - 1;
        amax[i] = a[i] + 1;  
    }

    for(int i = 0; i < N; i++){

        if(amin[i] >= 0)
            x[amin[i]]++;

        x[a[i]]++;
        x[amax[i]]++;
    }
    X = max_element(x.begin(), x.end()) - x.begin();
    for(int j = 0; j < N; j++){
        if(-1+X <= a[j] && a[j] <= X+1){
            countx++;
        }
    }

    cout << countx << endl;
    
    return 0;
}