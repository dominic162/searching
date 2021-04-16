/*
    Given a array find peak element in it.
*/


#include<iostream>
using namespace std;

class solution{
    public:
        int peakelement(int* a , int n);
};

int solution::peakelement(int* a , int n){

    int low=0, high=n-1, middle;

    for( ; low <= high ; ){

        middle = (low+high)/2;

        if( ( middle==0 || a[middle] > a[middle-1]) && ( middle==n-1 || a[middle] > a[middle+1]) ){
            return middle;
        }
        else{
            if( middle > 0 && a[middle] < a[middle-1] ){
                high = middle-1;
            }
            else{
                low = middle+1;
            }
        }

    }

}

int main(){

    int n;
    cout<<"Enter number of elements of array: ";
    cin>>n;

    int* arr=new int[n];
    cout<<"Enter elements of array: ";
    for(int i=0; i<n; ++i){
        cin>>arr[i];
    }

    solution sl;
    int ans=sl.peakelement(arr , n);

    cout<<"Peak element is "<<arr[ans]<<" which is at position "<<ans;

    return 0;
}