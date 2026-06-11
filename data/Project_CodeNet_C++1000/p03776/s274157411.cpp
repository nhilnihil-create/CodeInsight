#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, a, b;
    cin >> n >> a >> b;

    vector<double> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());

    double sum = 0;
    int count1 = 0;
    for(int i=0; i<a; i++){
        sum += v[i];
        if(v[i] == v[a-1]) count1 += 1;
    }
    double av = sum / (double)a;
    cout << fixed << setprecision(10) << av << endl;

    vector<vector<long long int>> c(51,vector<long long int>(51));
    for(int i=0; i<=50; i++){
        for(int j=0; j<=i; j++){
            if(j == 0 || j == i) c[i][j] = 1LL;
            else c[i][j] = c[i-1][j-1] + c[i-1][j];
        }
    }

    int count2 = 0;
    for(int i=0; i<n; i++){
        if(v[i] == v[a-1]) count2 += 1;
    }

    long long int ans = 0;
    if(v[0] != v[a-1]) ans = c[count2][count1];
    if(v[0] == v[a-1]){
        for(int i=a; i<=b; i++) ans += c[count2][i];
    }
    cout << ans << endl;
    return 0;
}