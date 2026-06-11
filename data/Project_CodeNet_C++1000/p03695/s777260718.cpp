#include<iostream>
#include<map>
using namespace std;

int main(){
    int N;
    cin >> N;
    map<string, bool> seen;
        seen["gray"] = false;
        seen["brown"] = false;
        seen["green"] = false;
        seen["skyblue"] = false;
        seen["blue"] = false;
        seen["yellow"] = false;
        seen["orange"] = false;
        seen["red"] = false;
        seen[""] = true;
    int cnt=0, all=0;
    for (int i=0; i<N; i++){
        int rate; cin >> rate;
        string colar="";
        if (rate<400) colar = "gray";
        else if (rate<800) colar = "brown";
        else if (rate<1200) colar = "green";
        else if (rate<1600) colar = "skyblue";
        else if (rate<2000) colar = "blue";
        else if (rate<2400) colar = "yellow";
        else if (rate<2800) colar = "orange";
        else if (rate<3200) colar = "red";
        else all++;
        if (seen[colar]) continue;
        seen[colar] = true;
        cnt++;
    }
    cout << max(1,cnt) << " " << cnt+all << endl;
    return 0;
}