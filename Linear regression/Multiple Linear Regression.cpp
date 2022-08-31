#include <iostream>
using namespace std;
int main() {

    float x[100][100] = {{2104, 5, 1, 45},
                         {1416, 3, 2, 40},
                         {852, 2, 1, 35}};
    float y[100] = {460, 232, 178};
    
    float m = 3, n = 4;
    float w[5] = {0.5,1,1.2,0.25};
    float b = 34;
    float J[100];
    float a = 0.0000001;
    int l = 2;
    int ite = 0;
    
    while(ite<100){
        float f[100] = {0,0,0,0};
    
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                f[i] += w[j]*x[i][j] + b;
            }
        }
        float cost = 0;
        float r = 0;
        for(int i = 0; i<n; i++){
            r += w[i]*w[i];
        }
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                w[j] = w[j] - (a/m)*((f[i] - y[i])*x[i][j] + l*w[j]); 
            }
            b = b - (a/m)*(f[i] - y[i]);
            cost += (1/(2*m))*(((f[i] - y[i])*(f[i] - y[i])) + l*r);
        }
        J[ite] = cost;
        ite++;
    }
    
    for(int i = 0; i<100; i++){
        cout<<J[i]<<endl;
    }
    
    return 0;
}