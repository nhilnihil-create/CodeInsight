#include <iostream>
using namespace std;

int N, M, a, b;
bool cek1[200010], cek2[200010];
int main () {
    cin >> N >> M;
    for (int i =1; i<=M; i++){
        cin >> a >> b;
        if (a==1){
            cek1[b] = true;
        }
        else if (b == N) {
            cek2[a]=true;
        }
    }
    // cari diantara pulau 2..N-1
    // mana pulau yg terhubung ke 1 dan juga ke N
    // yaitu yg (cek1[i] && cek2[i])
    bool valid = false;
    for (int i =1; i<=M; i++){
        if ((cek1[i]==true)&&(cek2[i]==true)){
            valid=true;
        }
    }
   if (valid == true) {
       cout<< "POSSIBLE" << endl;
   }     
   else {
       cout<< "IMPOSSIBLE" << endl;
   }
}
