#include <bits/stdc++.h>
using namespace std;

int N, i;
vector<int> a;

int main(){
    scanf("%d", &N);
    while(N){
        i = int(sqrt(N * 2));
        if(i * (i + 1) / 2 < N)i++;
        a.push_back(i);
        N -= i;
    }
    reverse(a.begin(), a.end());
    for(i = 0; i < a.size(); ++i){
        cout << a[i] << endl;
    }
    return 0;
}
