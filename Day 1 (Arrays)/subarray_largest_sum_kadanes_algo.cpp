#include <iostream>
using namespace std;

/*
    Calculates largest subarray sum and returns it using Kadane's Algorithm
    Time Complexity - O(n)
    Space Complexity - O(1)    
*/
int findLargestSubarraySumKadaneAlgo(int arr[],int n){
    int sum = 0, max = arr[0];
    for(int i = 0; i < n; i++){
        sum += arr[i]; 
        //If at any point of time sum > max, max is assigned to sum    
        if(sum > max) max = sum;  

        /*
            Below condition is checked and sum is assigned to zero 
            because we are finding maximum sum and we don't need negative sum
        */
        if(sum < 0) sum = 0;      
    }
    return max;
}

int main(){
    int n;
    cout << "Enter Size Of Array : ";
    cin >> n;
    int arr[n];
    cout << "Enter Array Elements : \n";
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Largest Sum Of Contiguous Subarray is " << findLargestSubarraySumKadaneAlgo(arr, n);    
    return 0;
}