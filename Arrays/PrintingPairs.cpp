
#include <iostream>
using namespace std;
void pairs(int arr[], int n){
for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
        cout<<arr[i]<<","<<arr[j]<<endl;
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

