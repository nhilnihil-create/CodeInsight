#include <iostream>
#include <vector>
using namespace std;
int d[100000][2];
vector<int> v[100000];
void f(int x, int y, int z){
    d[x][y] = z;
    for(int i=0;i<v[x].size();i++){
        if(d[v[x][i]][y] == -1){
            f(v[x][i], y, z+1);
        }
    }
}
int main(void){
    int n, c=0;
    cin >> n;
    for(int i=0;i<n-1;i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=0;i<n;i++){
        d[i][0] = d[i][1] = -1;
    }
    f(0, 0, 0);
    f(n-1, 1, 0);
    for(int i=0;i<n;i++){
        if(d[i][0] <= d[i][1]){
            c++;
        }
    }
    
    if(c*2 > n){
        cout << "Fennec" << endl;
    }else{
        cout << "Snuke" << endl;
    }
}
