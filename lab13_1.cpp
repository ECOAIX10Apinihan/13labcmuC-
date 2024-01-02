#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}

void stat(const double A[],int N,double B[]){
    double AM = 0,SD = 0,GM = 0,HM = 0,Max = A[0],Min = A[0],Xbar = 0,XSD = 0,XGM = 1,XHM = 0;
    for (int i = 0; i < N; i++)
    {
        Xbar += A[i];
        XGM *= A[i];
        XHM += (double) 1/A[i];
        if (A[i]>Max)
        {
            Max = A[i];
            B[4] = Max;
        }
        if (A[i] < Min)
        {
            Min = A[i];
            B[5] = Min;
        }
    }
    AM = Xbar/N;
    B[0] = AM;
    for (int i = 0; i < N; i++)
    {
        XSD += pow(A[i]-AM,2);
    }
    SD = sqrt(XSD/(N));
    B[1] = SD;
    GM = pow(XGM,(double)1/N);
    B[2] = GM;
    HM = N/(XHM);
    B[3] = HM;
}