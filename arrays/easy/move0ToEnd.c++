#include<bits/stdc++.h>
using namespace std;
void moveZeroToEndBrute(vector<int> &arr, int n){
    //create a temp array
    vector<int> temp;

    //iterate the main array and put all non zero numbers into temp
    for(auto it : arr){
        if(it != 0){
            temp.push_back(it);
        }
    }

    //count of nonzero numbers
    int k = temp.size();

    //iterate the main array and place the nonzero numbers from temp into the main array
    for(int i=0;i<k;i++){
        arr[i] = temp[i];
    }

    //fill the remaining place of main array with zero
    for(int i=k;i<n;i++){
        arr[i] = 0;
    }
}

void moveZeroToEndOptimal(vector<int> &arr, int n){
    //two pointer approach
    //i will point to the zero to be replaced
    //j will search and point to nonzero to replace the zero pointed by i
    int i = -1;
    int j;

    //search for the first zero, if none is found then return
    for(int k=0;k<n;k++){
        if(arr[k] == 0){
            //first zero found
            i = k;
            break;
        }
    }
    //no zero found
    if(i==-1)
    return;

    for(j=i+1;j<n;j++){
        if(arr[j] != 0){
            swap(arr[i],arr[j]);
            //i points to zero after i++
            i++;
        }
    }

}
int main(){
    vector<int> arr = {1,0,2,0,3,0};
    int n = arr.size();

    //moveZeroToEndBrute(arr,n);
    moveZeroToEndOptimal(arr,n);
    for(auto it : arr){
        cout<<it<<" ";
    }
    return 0;
}