#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstdlib>
#include<queue>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    long int n, m;
    cin >> n >> m;
    if (n >= m / 2){
        cout << (m / 2) << endl;
    }else{
        long int num = n * 2 + m;
        cout << num / 4 << endl;
    }
    
}
