#include <stdio.h>
#include <iostream>
using namespace std; 
int main(int argc, char **argv)
{
    float arr[]  = {1, 2, 23, 34, 1231, 45123.5555555,12, 23, 445, 312, 4512, 123, 12, 123};
    int n = sizeof(arr)/sizeof(arr[0]); 
    float max = arr[0];
    int indexMax = 0; 
    for(int i = 1; i < n; i++){
        if(arr[i] > max){
            max = arr[i];
            indexMax = i;
        }
    }
    cout << indexMax << endl; 
}
