//Time Complexity O(N^3)
#include <iostream>
using namespace std;
void pairs(int arr[], int n){
for(int i=0;i<n;i++){
    for(int j=i;j<n;j++){
        cout<<"(";
        for(int k=i;k<=j;k++)
        cout<<arr[k]<<",";
        cout<<")"<<endl;
    }
}

}
int main() {
	// your code goes here
    int arr[] = {1,2,3,4};
	int n = sizeof(arr)/sizeof(int);

	pairs(arr,n);

	return 0;
}

