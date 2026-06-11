#include <bits/stdc++.h>
#include <stdio.h>
#include <math.h>
using namespace std;
using vi = vector<int>;
using vll = vector<long long int>;
using vb = vector<bool>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<long long int>>;
using ll = long long int;
 
int main(){
    ll N; cin >> N;
    string S; cin >> S;
    string ans1 = "SS";
    string ans2 = "SW";
    string ans3 = "WS";
    string ans4 = "WW";
    bool t = true;
    for(int i=2; i<N; i++){
        if((ans1[i-1]=='S'&&S[i-1]=='o')||(ans1[i-1]=='W'&&S[i-1]=='x')){
            ans1.push_back(ans1[i-2]);
        }else{
            if(ans1[i-2]=='S'){
                ans1.push_back('W');
            }else{
                ans1.push_back('S');
            }
        }
    }
    if((ans1[N-1]=='S'&&S[N-1]=='o')||(ans1[N-1]=='W'&&S[N-1]=='x')){
        if(ans1[N-2] == ans1[0]){
            if((ans1[0]=='S'&&S[0]=='o')||(ans1[0]=='W'&&S[0]=='x')){
                if(ans1[N-1] == ans1[1]){
                    cout << ans1;
                    t = false;
                }
            }else{
                if(ans1[N-1] != ans1[1]){
                    cout << ans1;
                    t = false;
                }
            }
        }
    }else{
        if(ans1[N-2] != ans1[0]){
            if((ans1[0]=='S'&&S[0]=='o')||(ans1[0]=='W'&&S[0]=='x')){
                if(ans1[N-1] == ans1[1]){
                    cout << ans1;
                    t = false;
                }
            }else{
                if(ans1[N-1] != ans1[1]){
                    cout << ans1;
                    t = false;
                }
            }
        }
    }
    if(t){
    for(int i=2; i<N; i++){
        if((ans2[i-1]=='S'&&S[i-1]=='o')||(ans2[i-1]=='W'&&S[i-1]=='x')){
            ans2.push_back(ans2[i-2]);
        }else{
            if(ans2[i-2]=='S'){
                ans2.push_back('W');
            }else{
                ans2.push_back('S');
            }
        }
    }
    if((ans2[N-1]=='S'&&S[N-1]=='o')||(ans2[N-1]=='W'&&S[N-1]=='x')){
        if(ans2[N-2] == ans2[0]){
            if((ans2[0]=='S'&&S[0]=='o')||(ans2[0]=='W'&&S[0]=='x')){
                if(ans2[N-1] == ans2[1]){
                    cout << ans2;
                    t = false;
                }
            }else{
                if(ans2[N-1] != ans2[1]){
                    cout << ans2;
                    t = false;
                }
            }
        }
    }else{
        if(ans2[N-2] != ans2[0]){
            if((ans2[0]=='S'&&S[0]=='o')||(ans2[0]=='W'&&S[0]=='x')){
                if(ans2[N-1] == ans2[1]){
                    cout << ans2;
                    t = false;
                }
            }else{
                if(ans2[N-1] != ans2[1]){
                    cout << ans2;
                    t = false;
                }
            }
        }
    }
    }
    if(t){
    for(int i=2; i<N; i++){
        if((ans3[i-1]=='S'&&S[i-1]=='o')||(ans3[i-1]=='W'&&S[i-1]=='x')){
            ans3.push_back(ans3[i-2]);
        }else{
            if(ans3[i-2]=='S'){
                ans3.push_back('W');
            }else{
                ans3.push_back('S');
            }
        }
    }
    if((ans3[N-1]=='S'&&S[N-1]=='o')||(ans3[N-1]=='W'&&S[N-1]=='x')){
        if(ans3[N-2] == ans3[0]){
            if((ans3[0]=='S'&&S[0]=='o')||(ans3[0]=='W'&&S[0]=='x')){
                if(ans3[N-1] == ans3[1]){
                    cout << ans3;
                    t = false;
                }
            }else{
                if(ans3[N-1] != ans3[1]){
                    cout << ans3;
                    t = false;
                }
            }
        }
    }else{
        if(ans3[N-2] != ans3[0]){
            if((ans3[0]=='S'&&S[0]=='o')||(ans3[0]=='W'&&S[0]=='x')){
                if(ans3[N-1] == ans3[1]){
                    cout << ans3;
                    t = false;
                }
            }else{
                if(ans3[N-1] != ans3[1]){
                    cout << ans3;
                    t = false;
                }
            }
        }
    }
    }
    if(t){
    for(int i=2; i<N; i++){
        if((ans4[i-1]=='S'&&S[i-1]=='o')||(ans4[i-1]=='W'&&S[i-1]=='x')){
            ans4.push_back(ans4[i-2]);
        }else{
            if(ans4[i-2]=='S'){
                ans4.push_back('W');
            }else{
                ans4.push_back('S');
            }
        }
    }
    if((ans4[N-1]=='S'&&S[N-1]=='o')||(ans4[N-1]=='W'&&S[N-1]=='x')){
        if(ans4[N-2] == ans4[0]){
            if((ans4[0]=='S'&&S[0]=='o')||(ans4[0]=='W'&&S[0]=='x')){
                if(ans4[N-1] == ans4[1]){
                    cout << ans4;
                    t = false;
                }
            }else{
                if(ans4[N-1] != ans4[1]){
                    cout << ans4;
                    t = false;
                }
            }
        }
    }else{
        if(ans4[N-2] != ans4[0]){
            if((ans4[0]=='S'&&S[0]=='o')||(ans4[0]=='W'&&S[0]=='x')){
                if(ans4[N-1] == ans4[1]){
                    cout << ans4;
                    t = false;
                }
            }else{
                if(ans4[N-1] != ans4[1]){
                    cout << ans4;
                    t = false;
                }
            }
        }
    }
    }
    if(t){
        cout << -1;
    }
}