#include <stdio.h>

int main(int argc, char **argv)
{
    //Array used to check if the input frequencies are fire truck
    //double fireTruck[20] = {1000, 1175, 1242, 1292, 1333, 1365, 1393, 1424, 1445, 1476, 1375, 1273, 1174, 1075, 1011, 960, 894, 845, 796, 756};
    double fireTruckLow[20] = {878, 1089, 1210, 1268, 1314, 1350, 1380, 1410, 1436, 1426, 1324, 1224, 1125, 1043, 986, 927, 870, 821, 776, 700};
    double fireTruckHigh[20] = {1088, 1209, 1267, 1313, 1349, 1379, 1409, 1435, 1461, 1460, 1425, 1323, 1223, 1124, 1042, 985, 926, 869, 820, 775};
    //Array with the input frequencies
    double inputValues[20] = {904, 720, 996, 956, 1000, 1175, 1242, 1292, 1333, 1365, 1393, 1424, 1445, 1476, 1375, 1273, 1174, 1075, 1011, 960};
    
    //Records which index the match of the frequency was found
    int index = 0;
    //Checks if the next value of the input frequency is higher or lower that way we can determine which side of the spectogram the incoming signal is coming from
    int nextValHigh = 1; 
    if (inputValues[0] > inputValues[1]){
        nextValHigh = 0; 
    }
    
    // Uses the first half of the fire truck signal to determine which index it is  
    if(nextValHigh == 1){
        for(int i = 0; i < 20; i++){
            if((int)inputValues[0] <= fireTruckHigh[i] && (int)inputValues[0] >= fireTruckLow[i]){
                index = i;
            }
            if (i == 8){
                i = 18; 
            }
        }
    }
    // Uses the first half of the fire truck signal to determine which index it is
    else{
        for(int i = 9; i < 19; i++){
            if((int)inputValues[0] <= fireTruckHigh[i] && (int)inputValues[0] >= fireTruckLow[i]){
                index = i; 
            }
        }
    }
    //Counts the number of times there is a match with the fire truck
    int numMatches = 0;  
    
    //Algorithm that will detect if the incoming signal is a fire truck or not
    for(int i = 0; i < 20; i++){
        if((int)inputValues[i] <= fireTruckHigh[index] && (int) inputValues[i] >= fireTruckLow[index]){
            numMatches++; 
        }
            index++;
            //resets the index of the fire truck to 0
            if (index > 19){
                index = 0; 
            }
    }
    
    //Prints out of its a fire truck or not
    if(numMatches > 14){
        printf("It's a fire truck\n");
    }
    else printf("Its not a fire truck\n");
}
