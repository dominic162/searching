/*
    Given a number find its square root. If it is not a perfect square then return floor of its square root;
*/

#include<iostream>
using namespace std;

class solution{

    public:

        int sqroot(int x);

        solution(){}

};

int solution::sqroot(int x){

    int low=0,high=x,middle,ans;

    for( ; low <= high ; ){

        middle = (low + high)/2;

        if(middle*middle == x){
            return middle;
        }
        else{

            if(middle*middle < x){
                ans = middle;
                low = middle+1;
            }
            else{
                high = middle-1;
            }

        }

    }

    return ans;

}

int main(){

    int n;
    cout<<"Enter number for which you have to calculate square root: ";
    cin>>n;

    solution sl;

    int ans=sl.sqroot(n);
    cout<<"Square root of "<<n<<" is "<<ans;

    return 0;
}