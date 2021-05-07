/*
    Given a binary element, find length of longest subsequence in which no of 0s and 1s are equal;
*/

#include<iostream>
#include<unordered_map>
using namespace std;

class solution{
    public:
        int* make_arr(int n);

        int eq_01(int* arr,int n);

        void disp_arr(int* arr,int n);
};

void solution::disp_arr(int* arr,int n){
    cout<<"\nArray elements are: ";
    for(int i=0;i<n;++i){
        cout<<arr[i]<<" ";
    }
    return ;
}

int solution::eq_01(int* arr, int n){
    int mlen=0,csum=0;
    
    unordered_map<int,int> mp1;

    for(int i=0;i<n;++i){

        if(arr[i]==1){
            csum++;
        }
        else{
            csum--;
        }

        if(csum == 0){
            mlen=max(mlen,i+1);
        }

        if(mp1.find(csum) != mp1.end()){
            mlen=max(mlen,i-mp1[csum]);
        }
        else{
            mp1[csum]=i;
        }

    }

    return mlen;
}

int* solution::make_arr(int n){
    int* arr = new int[n];

    cout<<"Enter elements of array: ";
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }
    return arr;

}

int main(){
    solution sl;
    int n;
    cout<<"Enter number of elements in array: ";
    cin>>n;
    int* arr = sl.make_arr(n);

    cout<<"Max length of subarray with equal no of 0s and 1s is "<<sl.eq_01(arr,n);

    sl.disp_arr(arr,n);
    return 0;
}