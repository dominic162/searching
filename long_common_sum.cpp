/*
    Given 2 arrays, find if there exist subarray which start at same position and end at same position in both arrays and have equal sum;
*/

#include<iostream>
#include<unordered_map>
using namespace std;

class solution{
    public:
        int* make_arr(int n);

        int get_ans(int* arr1,int* arr2,int n);

        void disp_arr(int* arr,int n);
};

void solution::disp_arr(int* arr,int n){
    cout<<"\nArray elements are: ";
    for(int i=0;i<n;++i){
        cout<<arr[i]<<" ";
    }
    return ;
}

int solution::get_ans(int* arr1, int* arr2, int n){
    int mlen=0;

    int* temp = new int [n];

    unordered_map<int,int> mp1;

    for(int i=0;i<n;++i){
        temp[i]=arr1[i]-arr2[i];
    }
    int csum=0;
    for(int i=0;i<n;++i){
        
        csum+=temp[i];

        if(csum==0){
            mlen=max(mlen,i+1);
        }

        if(mp1.find(csum)!=mp1.end()){
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
    int* arr1 = sl.make_arr(n);
    int* arr2 = sl.make_arr(n);
    cout<<"Max length of subarray with sum same is "<<sl.get_ans(arr1,arr2,n);

    return 0;
}