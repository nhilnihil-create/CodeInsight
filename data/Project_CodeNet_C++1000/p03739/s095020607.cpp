#include<iostream>
#include<vector>

#define ll long long

using namespace std;

int main(){
    int n, a, i;
    ll s = 0, news, count1 = 0, count2 = 0;

    cin >> n;
    vector<ll> as(n);

    for(int i = 0; i < n; i++){
        cin >> a;
        s += a;
        as[i] = s;
    }

    i = 0;
    s = 0;
    while(i < n){
        news = as[i] + s;
        if(news > -1){
            s -= news + 1;
            count1 += news + 1;
        }
        if(++i >= n) break;

        news = as[i] + s;
        if(news < 1){
            s += 1 - news;
            count1 += 1 - news;
        }
        i++;
    }

    i = 0;
    s = 0;
    while(i < n){
        news = as[i] + s;
        if(news < 1){
            s += 1 - news;
            count2 += 1 - news;
        }
        if(++i >= n) break;

        news = as[i] + s;
        if(news > -1){
            s -= news + 1;
            count2 += news + 1;
        }
        i++;
    }

    cout << (count1 < count2 ? count1 : count2) << endl;
}