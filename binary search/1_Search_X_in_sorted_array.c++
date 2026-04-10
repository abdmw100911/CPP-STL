#include<bits/stdc++.h>
using namespace std;
void search(vector<int> arr, int target){
    //binary search using iterative approach
    int low = 0;
    int high = arr.size()-1;
    int mid;
    bool found = false;
    do{
        mid = (low+high)/2;
        if(arr[mid] == target){
            cout<<"element is at index "<<mid;
            found = true;
            break;
        }
        else if(arr[mid]<target){
            low = mid+1;
        }
        else if(arr[mid]>target){
            high = mid - 1;
        }
    }while(low<=high);

    if(!found){
        cout<<"element not found";
    }
}
int main(){
    vector<int> arr={1,2,3,4,5,6,7,8,9,10};
    int target;
    cout<<"enter the number to find in the array"<<endl;
    cin>>target;
    search(arr,target);
    return 0;
}