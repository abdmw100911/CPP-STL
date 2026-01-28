#include<iostream>
#include<vector>
using namespace std;
void selectionSort(vector<int> &arr, int n){
    //2 loops
    //outer loop -> steps(repetition)
    //inner loop for finding the minimum element index

    int minIndex;
    int temp;
    for(int i=0;i<n-1;i++){
        //for every repetition, min is the first element from which the loop starts
        minIndex = i;
        for(int j=i+1;j<n;j++){
            //finding the minimum
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        //swap the minimum with arr[i](first element of the loop)
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}
int main(){
    //selection sort
    //5 1 7 9 3
    vector<int> arr = {5,1,7,9,3,2,7};
    int n = arr.size();
    selectionSort(arr,n);

    //printing the sorted array
    for(auto it : arr){
        cout<<it<<" ";
    }

    //time complexity
    //best, worst, average : O(n2)
    return 0;
}