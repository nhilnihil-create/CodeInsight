#include<bits/stdc++.h>
using namespace std;

long long super_sum(vector<long long> s){
    if(s.size()== 1){
        return s.at(0);
    }
    else{
        long long a = s.at(0);
        long long b = s.at(1);
        vector<long long> t(s.size()-1);
        vector<long long> u(s.size()-1);
        t.at(0) = a*10 + b;
        u.at(0) = b;
        for (int i = 1; i < s.size()-1; i++)
        {
            t.at(i) = s.at(i+1);
            u.at(i) = s.at(i+1);
        }
        //return super_sum(t) + super_sum(u) + a * 2^(s.size()-2);
        long long xxx = super_sum(t);
        long long yyy = super_sum(u);
        return xxx + yyy + a * pow(2,s.size()-2);
    }
}

int main(){

    string s;
    cin >> s;
    int size = s.size();

    vector<long long> g(0);
    for (int i = 0; i < size; i++)
    {
        int x = s.at(i)-48;
        g.push_back(x);
    }
    cout << super_sum(g) << endl;
}