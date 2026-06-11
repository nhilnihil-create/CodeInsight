#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int tab [301][301];
int a[301][301];
int main() {
    int n;
    cin >> n;
    long long sum(0);
    for(int i = 1 ; i <= n ; i++)
    for(int j = 1 ; j <= n ; j++){
        cin >> tab[i][j];
    }
    for(int i = 1 ; i <= n ; i++)
    for(int j = 1 ; j <= n ; j++){
        for(int k = 1 ; k <= n ; k++){
            if(tab[i][j] > tab[i][k] + tab[j][k]){
                cout << -1;
                return 0;
            }
            if(tab[i][j] == tab[i][k] + tab[j][k] && k != i && k != j){
                    a[i][j] = 1;
            }
        }
    }
    for(int i = 1 ; i <= n ; i++)
    for(int j = 1 ; j <= n ; j++)
        if(a[i][j] == 0 ){
            sum += tab[i][j];
        }

    cout << sum/2;

    return 0;
}