#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;
int main() {
    int N, M;
    cin >> N >> M;
    int a[60], b[60];
    for(int i = 0; i < M; i++){
        cin >> a[i] >> b[i];

    }
    //バケット法
    int num[60] = {0};

    for(int i = 1; i <= N; i++){
        for(int j = 0; j < M; j++){
            if(a[j] == i || b[j] == i) ++num[i];
        }
    }
    for(int i = 1; i <= N; i++)
        cout << num[i] << endl;
    return 0;
}