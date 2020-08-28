#include <iostream>
using namespace std;

int findDuplicateNumber(int arr[]){
    //initializing fast and slow pointers to first element of the array    
    int slow = arr[0];
    int fast = arr[0];

    /*
        Hare Tortoise Algorithm
        Fast pointer (hare) moves twice as fast from the slow pointer (tortoise) until the first collision
        After the first collision fast pointer moves to first element and afterwards hare and tortoise move 1 step.
        After the second collision the fast or second pointer is the duplicate
        Time Complexity - O(n)
        Space Complexity - O(1)
    */

    //slow is iterating by 1 step where as fast is iterating by 2 steps
    do{
        slow = arr[slow];
        fast = arr[arr[fast]];        
    }while(fast != slow);

    //After 1st collision move the fast pointer to first element of the array
    fast = arr[0];

    //slow & fast both are iterating by 1 step
    while(fast != slow){
        slow = arr[slow];
        fast = arr[fast];
    }

    //you can return either slow or fast since both are same
    return slow;
}

int main(){
   int size;
   cout << "Enter Array Size (n+1) : "; 
   cin >> size;
   int arr[size];
   cout << "Enter Array Elements (1-n) : "; 
   for(int i = 0; i < size; i++)
       cin >> arr[i];
   cout << "Duplicate Number Is " << findDuplicateNumber(arr); 
   return 0; 
}