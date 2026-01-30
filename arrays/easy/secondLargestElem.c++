#include<iostream>
#include<vector>
using namespace std;
void secondLargestBrute(vector<int> arr, int n){
    
    //sort the array
    int j;
    int temp;
    //taking every element one by one
    for(int i=1;i<n;i++){
        //element locked for comparison
        j=i;
        //swap till left element is greater than current selected element
        while(j>0 && arr[j]<arr[j-1] ){
            //swap
            temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;

            //decrement j for comparison
            j--;
        }
    }
    //second last element of the sorted array is second largest
    cout<<arr[n-2];
}

void secondLargestBetter(vector<int> arr, int n){
    int largest=arr[0];
    //finding the largest element
    for(int i=1;i<n;i++){
        if(arr[i]>largest){
            largest = arr[i];
        }
    }

    int slargest=INT_MIN;
    //finding the second largest
    for(int i=0;i<n;i++){
        if(arr[i]>=slargest && arr[i]<largest){
            slargest = arr[i];
        }
    }
    cout<<slargest;
}

void secondLargestOptimal(vector<int> arr, int n){
    //better approcah but , finding largets and slargest in one loop
    //edge case: if array has 1 element only
    if(n<2){
        cout<<-1;
        return;
    }
    int largest = INT_MIN;
    int slargest = INT_MIN;

    for(int i=0;i<n;i++){
        if(arr[i]>largest){
            slargest = largest;
            largest = arr[i];
        }
        else if(arr[i]>=slargest && arr[i]<largest){
            slargest = arr[i];
        }
    }
    cout<<slargest;
}
int main(){
    vector<int> arr = {5,1,7,9,3};
    int n = arr.size();
    //secondLargestBrute(arr,n);
    //secondLargestBrute(arr,n);
    secondLargestOptimal(arr,n);
    return 0;
}