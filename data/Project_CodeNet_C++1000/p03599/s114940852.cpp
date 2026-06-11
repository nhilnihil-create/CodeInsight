#include <bits/stdc++.h>
#include <math.h>
using namespace std;
int main() {
int A , B, C, D, E, F;
cin >> A >> B >> C >> D >> E >> F;
double water, sugar_water;
double sugar, max_sugar;
double density = 0;
for(int i = 0; i <= F/(A*100); i++){
for(int j = 0; 100*(A*i + B*j) <= F; j++){
if(i == 0 && j == 0){continue;}
else water = 100*(A*i + B*j);
for(int k = 0; k <= F/C; k++){
for(int l = 0; (k*C + l*D) <= (E*water)/100; l++){
if(k == 0 && l == 0){continue;}
else sugar = (C*k + D*l);
if(sugar + water <= F){
if(density < sugar/(water + sugar)){
max_sugar = sugar;
sugar_water = water;
density = sugar/(sugar + water);}}}}}}
if(max_sugar == 0)cout << 100*A << " " << max_sugar << endl;
else cout << max_sugar + sugar_water << " " << max_sugar << endl;}