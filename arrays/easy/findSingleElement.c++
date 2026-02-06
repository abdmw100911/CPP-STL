#include<bits/stdc++.h>
using namespace std;
int findSingleElementBrute(vector<int> arr){
    int n = arr.size();
    int elem;
    int count;
    //for every element search for its corresponding duplicate element
    for(int i=0;i<n;i++){
        elem = arr[i];
        count = 0;
        for(int j=0;j<n;j++){
            if(arr[j] == elem){
                count++;
            }
        }
        if(count < 2){
            return elem;
        }
    }
    return -1;
}

int findSingleElemBetter(vector<int> arr){
    int n = arr.size();
    map<int,int> mp;
    //iterate the array and store the number and its count in the hashmap

    for(int i=0;i<n;i++){
        mp[arr[i]]++;
    }

    for(auto it : mp){
        if(it.second == 1){
            return it.first;
        }
    }
    return -1;
}

int findSingleElemOptimal(vector<int> arr){
    int n = arr.size();
        int xorr = 0;

        for(int i=0;i<n;i++){
            xorr = xorr ^ arr[i];
        }

        return xorr;
}
int main(){
    vector<int> arr = {1,2,2,1,3,4,5,3,4,5,9,9,10};
    //cout<<findSingleElementBrute(arr);
    cout<<findSingleElemBetter(arr);
    cout<<findSingleElemOptimal(arr);
    return 0;
}