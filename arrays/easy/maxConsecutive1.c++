#include<bits/stdc++.h>
using namespace std;
int maxConsecutiveOnes(vector<int> arr){
    int n = arr.size();
    int count = 0;
    int maxcount = 0;
    int i=0;
    while(i<n){
        if(arr[i] == 1){
            count++;
        }
        else if(arr[i] != 1){
            maxcount = max(maxcount,count);
            count = 0;
        }
        i++;
    }
    maxcount = max(maxcount,count);
    return maxcount;
}
int main(){
    vector<int> arr = {1,1,2,3,4,1,1,1,1,1,0,1};
    cout<<maxConsecutiveOnes(arr);
    return 0;
}