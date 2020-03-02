#include <stdio.h>
#include <math.h>
#include <complex.h>

//Global variables
double PI = M_PI; 
typedef double complex comp; 

//Compute FFT
void FFT2(comp arr[], comp arr2[], int n, int stepNum){
    if (stepNum < n){
        
        //Recrusive function
        FFT2(arr2, arr, n, stepNum*2);
        FFT2(arr2+stepNum, arr+stepNum, n, stepNum *2);
        
        //For loop to calculate the FFT
        for(int i = 0; i < n; i+= 2*stepNum){
            comp t = cexp(-I*PI*i/n)*arr2[i+stepNum];
            arr[i/2] = arr2[i] + t; 
            arr[(i+n)/2] = arr2[i] - t; 
        }
    }
}

void FFT(comp arr[], int n){
    //Makes a second array for computations
    comp arr2[n];
    
    //WHile loop to copy the components of array1 to array2
    int i = 0; 
    while (i < n){
        arr2[i] = arr[i]; 
        i++; 
    }
    
    //Actually computes the FFT. 
    FFT2(arr, arr2, n, 1);
}

int main(int argc, char **argv)
{
    //Array of numbers. Must be 2^n power. 
    comp arr[]  = {2, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 2, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0};
    //Gets the size of the array. 
    int arrSize = sizeof(arr)/sizeof(arr[0]);
    //Computes the FFT of the array. 
    FFT(arr, arrSize);
    
    //Prints the values
    for(int i = 0; i < arrSize; i++){
        if(!cimag(arr[i]))
            printf("%g\n", creal(arr[i]));
        else{
            if(cimag(arr[i]) < 0){
            printf("%g - %gi\n ", creal(arr[i]), (cimag(arr[i])*-1));
            }
            else printf("%g + %gi\n ", creal(arr[i]), cimag(arr[i]));
     }
    }
    return 0;
}
