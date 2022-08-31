#include<iostream>
#include<bits/stdc++.h>

using namespace std;
int main(){
    
    float x[100][100] = {{0.5, 1.5}, {1,1}, {1.5, 0.5}, {3, 0.5}, {2, 2}, {1, 2.5}};
    float y[100] = {0, 0, 0, 1, 1, 1};
    
    float m = 6, n = 2;
    float w[4] = {0.5, 0.75};
    float b = 0.5;
    float J[100];
    float a = 6.5;
    float l = 2;
    int ite = 0;
    
    while(ite<50){
        float f[10] = {0,0,0,0,0,0,0};
            
        for(int i = 0; i<m; i++){
            float z = 0;
            for(int j = 0; j<n; j++){
                z += w[j]*x[i][j] + b;
            }
            f[i] = 1/(1+pow(2.718281828459045,(-(z))));
        }
        float cost = 0, r = 0;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                w[j] = w[j] - (a/m)*((f[i]-y[i])*x[i][j]);
            }
            b = b - (a/m)*(f[i] - y[i]);
            cost -= (1/(2*m))*(((y[i])*(log(f[i]))) + ((1-y[i])*(log(1-f[i]))));
        }
        J[ite] = cost;
        ite++;
    }
    for(int i = 0; i<50; i++){
        cout<<J[i]<<endl;
    }
    
    
    return 0;
}