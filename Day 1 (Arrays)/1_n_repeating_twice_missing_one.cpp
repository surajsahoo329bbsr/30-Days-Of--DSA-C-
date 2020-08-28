#include <iostream>
using namespace std;

void findRepeatingMissingNumber(int arr[], int n, int *repeating,  int *missing){
    
    int y = 0, xSqMinusYSq, xMinusY, sqY = 0;

    //Taking sum of array elements and sum of squared array elements
    for(int i=0; i<n; i++){
        y += arr[i];
        sqY += arr[i] * arr[i];
    }

    /*
        By Taking x2 - y2 value and x - y value we can get values of x and y;
        Missing number is x and repeating number is y (occurs twice)
    */

    //x - y = sum upto n integers - sum of all array elements ----- (Equation 1)
    xMinusY = (n * (n + 1)/ 2) - y;
    //x^2 - y^2 = sum upto n squared integers - sum of all array squared elements  ----- (Equation 2)
    xSqMinusYSq = ((n * (n + 1) * (2*n + 1))/ 6) - sqY;

    //By solving equation 1 and 2 we get 
    int xPlusY = xSqMinusYSq / xMinusY;

    // x = (x+y)(x-y) / 2
    *repeating = (xPlusY + xMinusY) / 2;
    // y = (x+y) - y
    *missing = xPlusY - *repeating;
}

int main(){
    int n, repeating, missing;
    cout << "Enter Size Of Array : ";
    cin >> n;
    int arr[n];
    cout << "Enter Array Elements (1 to n, 1 missing number, 1 repeating number not more than twice) \n";
    for(int i=0; i<n; i++)
        cin >> arr[i];
    findRepeatingMissingNumber(arr, sizeof(arr)/sizeof(arr[0]), &repeating, &missing);
    cout << "Repeating Number : " << repeating << ", Missing Number : " << missing;
    return 0;
}