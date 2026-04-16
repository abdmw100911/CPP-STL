#include<iostream>
using namespace std;
int findnthRoot(int num, int n){
    int low = 1;//lowest possible answer 
    int high = num/2;
    int mid;
    long long ans;;
    while(low<=high){
        //re initializing answer for every iteration
        ans = 1;
        mid = (low+high)/2;
        for(int i = 0;i<n;i++){
            ans = mid*ans;
        }
        if(ans == num){
            return mid;
        }
        else if (ans < num){
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    //perfect nth root of number is not found(doesnt exist)
    return -1;
}
int main(){
    int val = 343;
    int n = 3;
    //to find the cube root of 343
    cout<<findnthRoot(val,n)<<" is the "<<n<<"th "<<"root of "<<val<<endl;
    return 0;
}