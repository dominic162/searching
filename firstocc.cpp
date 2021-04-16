/*
    Given a sorted array.
*/

#include<iostream>
using namespace std;

class solution{
    private:
        int n;
        int* arr;

    public:

        void setarr();
        
        int getfirstocc(int target);

        int getlastocc(int target);

        solution(int n){
            this->n = n;
            this->arr = new int[n];
        }

};

void solution::setarr(){

    cout<<"Enter elements of array: ";
    for(int i=0;i<n; ++i){
        cin>>this->arr[i];
    }

    return ;
}

//Get first occurence of element

int solution::getfirstocc(int target){

    int start=0,end=this->n-1,middle;

    for( ; start <= end; ){
        middle = (start+end)/2;

        if(arr[middle] == target){

            if(middle == 0 || arr[middle] != arr[middle-1]){
                return middle;
            }
            end=middle-1;
        }
        else{

            if(arr[middle] > target){
                end=middle-1;
            }
            else{
                start=middle+1;
            }

        }

    }

    return -1;
}

//Get last occurence of element

int solution::getlastocc(int target){

    int start=0,end=this->n-1,middle;

    for( ; start <= end ; ){
        middle = (start+end)/2;

        if(arr[middle] == target){

            if(middle == n-1 || arr[middle] != arr[middle+1]){
                return middle;
            }

            start = middle+1;

        }
        else{

            if(arr[middle] > target){
                end = middle - 1;
            }
            else{
                start = middle + 1;
            }

        }

    }

    return -1;

}

int main(){

    int n;
    cout<<"Enter number of elements of array: ";
    cin>>n;

    solution sl(n);

    sl.setarr();

    int target;
    cout<<"Enter element to get first occ: ";
    cin>>target;
    int pos;
    pos = sl.getfirstocc(target);

    if(pos == -1){
        cout<<target<<" is not present in array.";
    }
    else{
        cout<<target<<" is firstly present at "<<pos<<" position.";
    }

    cout<<"\nEnter element to get last occ: ";
    cin>>target;
    pos = sl.getlastocc(target);

    if(pos == -1){
        cout<<target<<" is not present in array.";
    }
    else{
        cout<<target<<" is lastly present at "<<pos<<" position.";
    }


    return 0;
}