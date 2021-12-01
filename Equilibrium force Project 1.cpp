#include <iostream>
#include <cmath>
using namespace std;

void hazemFun(double &rightAngle, double &leftAngle,double &weight)
{
    //requesting the inputs from the user    
    cout << "Type the Right Angle in degree: ";
    cin >> rightAngle;
    
    cout << "Type the Left Angle in degree: ";
    cin >> leftAngle;
    
    cout << "Type the Weight in newton: ";
    cin >> weight;
    
    rightAngle = rightAngle * (2 * 3.14) / 360;
    leftAngle = leftAngle * (2 * 3.14) / 360;
}

void omarFun(double &rightAngle, double &leftAngle,double &weight, double arr[][3])
{
    // an array with 2 rows and 3 columns.
    arr[0][0] = cos(rightAngle);
    arr[0][1] = -1 * cos(leftAngle);
    arr[0][2] = 0; 
    
    arr[1][0] = sin(rightAngle);
    arr[1][1] = sin(leftAngle);
    arr[1][2] = weight;
}

void shahdFun(double arr[][3])
{
    // preparing the equation to answer using simultaneous method
    double factorRow1 = -1*arr[0][0];
    double factorRow2 = arr[1][0];
   
    arr[1][0] *= factorRow1;
    arr[1][1] *= factorRow1;
    arr[1][2] *= factorRow1;
      
    arr[0][0] *= factorRow2;
    arr[0][1] *= factorRow2;
    arr[0][2] *= factorRow2;
}

void heshamFun(double arr[][3], double &force1Val, double &force2Val) {
    // calculating the coof results
    double cof_Y = arr[0][1] + arr[1][1];
    double rhs = arr[0][2] + arr[1][2];
    force2Val = rhs / cof_Y;
    force1Val = -1 * force2Val * arr[0][1] / arr[0][0];
}

void ranaFun() {
    
}

int main() {
    char again;
    double rightAngle, leftAngle, weight, force1Val, force2Val;
    double arr[2][3] = {0};

    do
    {
        hazemFun(rightAngle, leftAngle, weight);
        
        omarFun(rightAngle,leftAngle,weight, arr);
        
        shahdFun(arr);
        
        heshamFun(arr, force1Val, force2Val);
        
        cout << "Right Force = " << force1Val << endl;
        cout << "Left Force = " << force2Val;

        cout << "\nAnother calculation Y / N ? ";
        cin >> again;
    }
    while(again == 'y' || again == 'Y');
    return 0;
}