#include <bits/stdc++.h>
using namespace std;

typedef long long  ll;

ll MOD = 1000000007;
ll INF = 100000000000;
double PI = 3.1415926535;

template<typename T>
void remove(std::vector<T>& vector, unsigned int index)
{
    vector.erase(vector.begin() + index);
}
int N;
int ans = 0;
char field[5010][5010];
vector<pair<int,int>> A(N);

void search(int n){
    int x = A[n].first,y = A[n].second;
    for(int i = 0;i < N;i++){
        if(i != n){
            bool frag = 1;
            int dx = A[i].first - x,dy = A[i].second - y;
            if(field[A[i].first+dy][A[i].second+dx] != '#')frag = 0;
            if(field[A[i].first+dy][A[i].second+dx] != '#')frag = 0;
        }
    }
}

int main(){
    int H,W,N;
    cin >> H >> W >> N;
    vector<int> A(N);
    for(int i = 0;i < N;i++){
        cin >> A[i];
    }
    int table[110][110];
    queue<int> Q;
    for(int i = 0;i < N;i++){
        int n = A[i];
        for(int j = 0;j < n;j++){
            Q.push(i+1);
        }
    }
    bool frag = 1;
    for(int i = 0;i < H;i++){
        if(frag){
            for(int j = 0;j < W;j++){
                table[i][j] = Q.front();
                Q.pop();
            }
            frag = 0;
        }else{
            for(int j = W-1;j >= 0;j--){
                table[i][j] = Q.front();
                Q.pop();
            }
            frag = 1;
        }
    }
    for(int i = 0;i < H;i++){
        for(int j = 0;j < W;j++){
            cout << table[i][j] << ' ';
        }
        cout << endl;
    }
}
