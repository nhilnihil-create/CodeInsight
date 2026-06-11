#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <queue>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <climits>
using namespace std;

#define MOD1097 1000000007

#define ll long long
#define pint pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define mpair make_pair
#define pm(first, second) pb(mpair(first, second))
#define SPACE " "
#define fpf first.first
#define fps first.second
#define spf second.first
#define sps second.second

#define all(X) (X).begin(), (X).end()
#define reall(X) (X).rbegin(), (X).rend()
#define divcel(a, b) (((a) + ((b) - 1)) / (b))

int main(){
    
    int N;
    string S;
    cin >> N >> S;
    vector<int> V(N);
    bool able = false, flag1, flag2;
    //S=1, W=-1
    //SS
    V[0] = 1;
    V[1] = 1;
    for(int i = 1; i < N - 1; i++){
        if(V[i] == 1){
            if(S[i] == 'o'){
                V[i + 1] = V[i - 1];
            }
            else{
                V[i + 1] = -V[i - 1];
            }
        }
        else{
            if(S[i] == 'o'){
                V[i + 1] = -V[i - 1];
            }
            else{
                V[i + 1] = V[i - 1];
            }
        }
    }
    flag1 = false;
    flag2 = false;
    if(V[0] == 1){
        if(S[0] == 'o'){
            if(V[1] == V[N-1])flag1 = true;
        }
        else{
            if(V[1] != V[N-1])flag1 = true;
        }
    }
    else{
        if(S[0] == 'o'){
            if(V[1] != V[N-1])flag1 = true;
        }
        else{
            if(V[1] == V[N-1])flag1 = true;
        }
    }
    if(V[N-1] == 1){
        if(S[N-1] == 'o'){
            if(V[N-2] == V[0])flag2 = true;
        }
        else{
            if(V[N-2] != V[0])flag2 = true;
        }
    }
    else{
        if(S[N-1] == 'o'){
            if(V[N-2] != V[0])flag2 = true;
        }
        else{
            if(V[N-2] == V[0])flag2 = true;
        }
    }
    if(flag1 && flag2){
        for(int i = 0; i < N; i++){
            if(V[i] == 1)cout << "S";
            else cout << "W";
        }
        cout << endl;
        return 0;
    }
    //SW
    V[0] = 1;
    V[1] = -1;
    for(int i = 1; i < N - 1; i++){
        if(V[i] == 1){
            if(S[i] == 'o'){
                V[i + 1] = V[i - 1];
            }
            else{
                V[i + 1] = -V[i - 1];
            }
        }
        else{
            if(S[i] == 'o'){
                V[i + 1] = -V[i - 1];
            }
            else{
                V[i + 1] = V[i - 1];
            }
        }
    }
    flag1 = false;
    flag2 = false;
    if(V[0] == 1){
        if(S[0] == 'o'){
            if(V[1] == V[N-1])flag1 = true;
        }
        else{
            if(V[1] != V[N-1])flag1 = true;
        }
    }
    else{
        if(S[0] == 'o'){
            if(V[1] != V[N-1])flag1 = true;
        }
        else{
            if(V[1] == V[N-1])flag1 = true;
        }
    }
    if(V[N-1] == 1){
        if(S[N-1] == 'o'){
            if(V[N-2] == V[0])flag2 = true;
        }
        else{
            if(V[N-2] != V[0])flag2 = true;
        }
    }
    else{
        if(S[N-1] == 'o'){
            if(V[N-2] != V[0])flag2 = true;
        }
        else{
            if(V[N-2] == V[0])flag2 = true;
        }
    }
    if(flag1 && flag2){
        for(int i = 0; i < N; i++){
            if(V[i] == 1)cout << "S";
            else cout << "W";
        }
        cout << endl;
        return 0;
    }
    //WS
    V[0] = -1;
    V[1] = 1;
    for(int i = 1; i < N - 1; i++){
        if(V[i] == 1){
            if(S[i] == 'o'){
                V[i + 1] = V[i - 1];
            }
            else{
                V[i + 1] = -V[i - 1];
            }
        }
        else{
            if(S[i] == 'o'){
                V[i + 1] = -V[i - 1];
            }
            else{
                V[i + 1] = V[i - 1];
            }
        }
    }
    flag1 = false;
    flag2 = false;
    if(V[0] == 1){
        if(S[0] == 'o'){
            if(V[1] == V[N-1])flag1 = true;
        }
        else{
            if(V[1] != V[N-1])flag1 = true;
        }
    }
    else{
        if(S[0] == 'o'){
            if(V[1] != V[N-1])flag1 = true;
        }
        else{
            if(V[1] == V[N-1])flag1 = true;
        }
    }
    if(V[N-1] == 1){
        if(S[N-1] == 'o'){
            if(V[N-2] == V[0])flag2 = true;
        }
        else{
            if(V[N-2] != V[0])flag2 = true;
        }
    }
    else{
        if(S[N-1] == 'o'){
            if(V[N-2] != V[0])flag2 = true;
        }
        else{
            if(V[N-2] == V[0])flag2 = true;
        }
    }
    if(flag1 && flag2){
        for(int i = 0; i < N; i++){
            if(V[i] == 1)cout << "S";
            else cout << "W";
        }
        cout << endl;
        return 0;
    }
    //WW
    V[0] = -1;
    V[1] = -1;
    for(int i = 1; i < N - 1; i++){
        if(V[i] == 1){
            if(S[i] == 'o'){
                V[i + 1] = V[i - 1];
            }
            else{
                V[i + 1] = -V[i - 1];
            }
        }
        else{
            if(S[i] == 'o'){
                V[i + 1] = -V[i - 1];
            }
            else{
                V[i + 1] = V[i - 1];
            }
        }
    }
    flag1 = false;
    flag2 = false;
    if(V[0] == 1){
        if(S[0] == 'o'){
            if(V[1] == V[N-1])flag1 = true;
        }
        else{
            if(V[1] != V[N-1])flag1 = true;
        }
    }
    else{
        if(S[0] == 'o'){
            if(V[1] != V[N-1])flag1 = true;
        }
        else{
            if(V[1] == V[N-1])flag1 = true;
        }
    }
    if(V[N-1] == 1){
        if(S[N-1] == 'o'){
            if(V[N-2] == V[0])flag2 = true;
        }
        else{
            if(V[N-2] != V[0])flag2 = true;
        }
    }
    else{
        if(S[N-1] == 'o'){
            if(V[N-2] != V[0])flag2 = true;
        }
        else{
            if(V[N-2] == V[0])flag2 = true;
        }
    }
    if(flag1 && flag2){
        for(int i = 0; i < N; i++){
            if(V[i] == 1)cout << "S";
            else cout << "W";
        }
        cout << endl;
        return 0;
    }
    cout << "-1" << endl;

    return 0;
}