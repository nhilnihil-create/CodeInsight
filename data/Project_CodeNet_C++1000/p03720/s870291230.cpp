#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    vector<int> b(m);
    vector<int> c(n,0);
    for(int i = 0; i < m; i++){
        cin >> a.at(i) >> b.at(i);
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a.at(j) == i+1 || b.at(j) == i+1){
                c.at(i) += 1;
            }
        }
    }
    for(int i = 0; i < n; i++){
        cout << c.at(i) << endl;
    }
    return 0;
}