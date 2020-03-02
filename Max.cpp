#include <stdio.h>
#include <iostream>
using namespace std; 
int main(int argc, char **argv)
{
    //Setting up an array
    float arr[]  = {1, 2, 23, 34, 1231, 45123.5555555,12, 23, 445, 312, 4512, 123, 12, 123};
    
    //Determines the size of the array
    int n = sizeof(arr)/sizeof(arr[0]); 
    
    //Setting up the two variables, max and indexMax to save the Max value and index of that max value
    float max = arr[0];
    int indexMax = 0; 
    
    //For loop to go through the whole array to determine the max and its index
    for(int i = 1; i < n; i++){
        //if another number that is larger than the first max is found, it will be saved as the new max
        if(arr[i] > max){
            max = arr[i];
            indexMax = i;
        }
    }
    
    //prints out the result of the max
    cout << "Index of the max is: " << indexMax << endl; 
}
