#include <iostream>
#include <cstring>
using namespace std;
bool check[100005];
int main(){

    int n, m, x, y, arr[100005], score=0;
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        arr[i]=1;
    }
    check[1]=true;
    for(int i=1; i<=m; i++){
        cin >> x >> y;
        if(check[x]==true){
            if(arr[x]==1){
                check[x]=false;
                check[y]=true;
                arr[y]++;
            }
            else{
                check[y]=true;
                arr[y]++;
            }
            arr[x]--;
        }
        else{
            arr[y]++;
            arr[x]--;
        }
    }
    for(int i=1; i<=n; i++){
        if(check[i]){
            score++;
        }
    }
    cout << score << endl;
    return 0;
}