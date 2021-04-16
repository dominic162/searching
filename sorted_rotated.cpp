/*
    Given a sorted and rotated array. Find if a element is present in it;
*/


#include<iostream>
using namespace std;

class solution{
    public:
        int search(int* a , int n , int target);
};

int solution::search(int* a , int n , int target){
    
    int low=0 , high=n-1, middle;

    for( ; low <= high ; ){

        middle = (low+high)/2;

        if( a[middle] ==  target){
            return middle;
        }
        else{

            if( a[low] <= a[middle] ){

                if( a[low] <= target && target <= a[middle] ){
                    high = middle-1;
                }
                else{
                    low = middle+1;
                }

            }
            else{

                if( a[high] >= target && target >= a[middle] ){
                    low = middle+1;
                }
                else{
                    high = middle-1;
                }

            }

        }

    }
    
    return -1;
}


int main(){

    int n;
    cout<<"Enter number of elements in array: ";
    cin>>n;

    int* arr = new int[n];

    cout<<"Enter elements in array: ";
    for(int i=0; i<n ; ++i){
        cin>>arr[i];
    }

    solution sl;

    int target;
    cout<<"Enter element to be searched: ";
    cin>>target;

    int ans = sl.search(arr , n , target);

    if(ans != -1){
        cout<<target<<" is present at "<<ans;
    }
    else{
        cout<<target<<" is not present ";
    }

    return 0;
}