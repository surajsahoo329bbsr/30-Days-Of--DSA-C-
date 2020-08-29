#include <iostream>
using namespace std;

//swap function with 2 variables
void swap(int *a, int *b){
    *a = *a + *b;
    *b = *a - *b;
    *b = *a - *b;
}

//method to find initial gap 
int findGap(int n1, int n2){
    if((n1 + n2)% 2 != 0)
        return (n1+n2)/2 + 1;
    return (n1+n2)/2;    
}

//n1 = size of arr1, n2 = size of arr2
//n1 > n2 i.e. arr1 size > arr2 size
//This function has Space Complexity Of O(1) & Time Complexity (nlog n)
void merge2SortedArraysGapAlgo(int arr1[], int n1, int arr2[], int n2){    
    int gap = findGap(n1, n2);
    /*
        Initializing iFlag and jFlag for each loop because we will initialize variables
        before an array goes out of bounds after an iteration
    */
    bool iFlag = false, jFlag = false;

    // i = 1st index, j = 2nd index
    for (int i = 0, j = gap; gap != 0; i++, j++){
        
        //Checks if first i doesn't go out of bounds for arr1 
        if(i == n1){
            i = 0;
            //Intializing iFlag to true to check swapping conditions  
            iFlag = true;
        }
        
        //Checks if first j doesn't go out of bounds for arr2 
        if(j == n1){
            j = 0;
            //Intializing iFlag to true to check swapping conditions  
            jFlag = true;
        }

        /*
            Below code (52-65) will check the indices in their respective arrays
            To refrain from using 3rd array concept for better space complexity  
            this part is checked and swapped once the (element in index i) > (element in index j)
        */
       
        //If i and j indices is in arr1
        if(!iFlag && !jFlag){
            if(arr1[i] > arr1[j])
                swap(arr1[i], arr1[j]);
        }
        //If i index is in arr1 and j index is in arr2
        else if(!iFlag && jFlag){
            if(arr1[i] > arr2[j])
                swap(arr1[i], arr2[j]);
        }
        //Both i and j indices are in arr2 because size of arr1 (n1) > size of arr2 (n2)
        else{
            if(arr2[i] > arr2[j])
                swap(arr2[i], arr2[j]);
        }

        /*
            Checks if 2nd index j is out of bounds for arr1 or not
            If it is out of bounds for arr1 we need to check for jFlag condition 
            since n2 < n1 & this condition will be true even if 2nd index has not crossed arr1
        */
        if(j == n2 -1 && jFlag){ 
            i = 0;
            gap /= 2;
            j = gap;   
            iFlag = false;
            jFlag = false;
        }
    }
}

int main(){
    int n, m;
    cout << "Enter Size Of Array1(n) & Array2(m) Respectively (n != m) : ";
    cin >> n >> m;
    int arr1[n], arr2[m];
    cout << "Enter Sorted Elements (Ascending) Of Array1 \n"; 
    for(int i = 0; i < n; i++)
        cin >> arr1[i]; 
    cout << "Enter Sorted Elements (Ascending) Of Array2 \n"; 
    for(int i = 0; i < m; i++)
        cin >> arr2[i];   
    if(n > m)
        merge2SortedArraysGapAlgo(arr1, n, arr2, m);
    else
        merge2SortedArraysGapAlgo(arr2, m, arr1, n);

    cout << "After Sorting...\nArray1 : ";
    for (int i = 0; i < n; i++)
        cout << arr1[i] << " ";

    cout << "\nArray2 : ";
    for (int i = 0; i < m; i++)
        cout << arr2[i] << " ";   
                      
    return 0;
}