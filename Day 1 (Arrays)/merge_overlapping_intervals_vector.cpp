#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

/*
    Below Alogorithm Has A Time Complexity Of O(nlogn)(Sorting) + O(n)(For comparing and Setting values to Merged vector)
    Space Complexity is O(n) (Worst Case)
*/
vector <vector <int>> mergeOverlappingIntervals2DVector(vector <vector <int>> interval){
    vector <vector <int>> mergedIntervals;    

    //sorting the passed interval (vector of vectors)
    sort(interval.begin(), interval.end());

    //If vector size is zero return the interval
    if(interval.size() == 0)
        return interval;

    //Intializing tempInterval vector to 1st vector of interval    
    vector <int> tempInterval = interval[0];

    //auto keyword specifies type of variable that is being declared will be automatically deducted from initializer (good alternative for long for loops for each iteration)
    for(auto it : interval){
        /*
            Below condition checks that if at any point of time, if first element of it < second element of tempInterval
            take max of their 2nd elements and merge
        */
        if(it[0] <= tempInterval[1])
            //Assigning 2nd element of tempInterval to maximum of the 2nd elements of it and tempInterval to be merged
            tempInterval[1] = max(it[1], tempInterval[1]);
        else{
            //If above condition fails then merge the intervals
            mergedIntervals.push_back(tempInterval);
            tempInterval = it; //updating tempInterval to it so that from next iteration a new tempInterval is checked
        }        
    } 

    //Pushing last resultant interval into the merged interval
    mergedIntervals.push_back(tempInterval);
    return mergedIntervals;
}

int main(){
    int ele1, ele2, n;
    vector <int> set;
    vector <vector <int>> interval;
    vector <vector <int>> mergedInterval;
    cout << "Enter The Size Of The Vector : ";
    cin >> n;

    for(int i = 0; i < n; i++){
        cout << "Enter 2 elements at position " << (i + 1) << " : ";
        //reading 2 elements of the set
        cin >> ele1;
        cin >> ele2;
        //pushing two elements into the set
        set.push_back(ele1);
        set.push_back(ele2);
        //pushing the set into the interval vector since datatype of interval vector is vector < vector <int>>
        interval.push_back(set); 

        //after pushing back into interval vector clearing set vector else the interval will pile up previous data
        //If I do not write this interval vector will look something like this even if 2 elements are pushed in each set
        // [[1,2], [1,2,3,4], [1,2,3,4,5,6],....] which is undesirable      
        set.clear();      
    }

    mergedInterval = mergeOverlappingIntervals2DVector(interval);

    cout << "Merged Elements Are : " << endl;
    cout << "[ ";
    for(int i = 0; i < mergedInterval.size(); i++){
        cout << "[ ";
        for(int j = 0; j < mergedInterval[i].size(); j++){
            cout << mergedInterval[i][j];
            if(j != mergedInterval[i].size() - 1)
                cout << ", ";
        }
        cout << "], ";  
    }
    cout << "]";
    return 0;
}