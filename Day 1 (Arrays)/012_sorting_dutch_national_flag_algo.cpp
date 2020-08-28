#include <iostream>
using namespace std;

void swap(int *a, int *b){
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

void sortArrayDutchNationalFlagAlgo(int arr[], int n){
    int low = 0; //low assigned to first element
    int mid = 0; //mid assigned to first element
    int high = n -1; //high assigned to last element of array

    /*
        Dutch National Flag Algorithm
        arr[0 to low-1] = 0
        arr[low to mid-1] = 1
        arr[high+1 to n-1] = 2
        The above criteria is maintained in every pass
        Time Complexity - O(n)
        Space Complexity - O(1)
    */

    while(mid <= high){
        switch(arr[mid]){
            case 0 :
                swap(&arr[low++], &arr[mid++]);
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(&arr[mid], &arr[high--]);
                break;        
        }
    }

}

int main(){
    int n;
    cout << "Enter Size Of Array : ";
    cin >> n; 
    int arr[n];
    cout << "Enter Array Elements (0, 1, 2 Only) : ";
    for(int i=0; i<n; i++)
        cin >> arr[i];

    sortArrayDutchNationalFlagAlgo(arr, sizeof(arr)/sizeof(arr[0])); 
    
    cout << "Sorted Array \n"; 
    for(int i=0; i< n ; i++)
        cout << arr[i] << " "; 

    return 0;
}