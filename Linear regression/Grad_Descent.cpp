#include<iostream>
using namespace std;
int main(){
    float x_train[100] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    float y_train[100] = {300, 500, 750, 1000, 1200, 1290, 1400, 1600, 1800, 2000};
    float f[100], J[100];
    float w = 400, b = 50, cost = 0, a = 0.01;
    int n = 0;
    float x = 0.1;
    while(n<200){
        for(int i = 0; i<10; i++){
            f[i] = (w*x_train[i])+b;
        }
        float cost = 0;
        for(int i = 0; i<10; i++){
            w = w - a*(x)*(f[i]-y_train[i])*x_train[i];
            b = b - a*(x)*(f[i]-y_train[i]);
            cost += (x/2)*((f[i]-y_train[i])*(f[i]-y_train[i]));
        }
    J[n] = cost;
    n++;
    }
    // cout<<"w = "<<w<<endl<<"b = "<<b<<endl;
    
    for(int i = 0; i<100; i++){
        cout<<J[i]<<endl;
    }

    int x_axis[100];

    return 0;
}