#include<iostream>
#include<cstring>

using namespace std;

int box[100005];
bool red[100005];

int main(){
    int N, M, ans = 0;
    cin >> N >> M;
    memset(red, 0, sizeof(red));
    for(int i=1; i<=N; i++) box[i] = 1;

    red[1] = 1;
    for(int i=1; i<=M; i++){
        int x, y;
        cin >> x >> y;

        if(red[x]) red[y] = 1;
        box[x]--; box[y]++;
        if(box[x] == 0) red[x] = 0;
    }

    for(int i=1; i<=N; i++){
        if(red[i]) ans++;
    }

    cout << ans << endl;
}