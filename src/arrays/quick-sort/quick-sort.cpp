/**
 * quick-sort.cpp
 * Contains method and client code to implement quick sort algorithm
 * Author: Vaibhav Pujari
 * Last Updated: Feb 9, 2015
 * Updated By: Vaibhav Pujari
 */
#include <vector>
#include <iostream>

using namespace std;

/**
 * Function - printVector
 * Prints vector to console
 */
void printVector(const vector<int> &ar) {
    cout<<" ";
    for(vector<int>::const_iterator ia = ar.begin(); ia < ar.end(); ia++) {
        cout<<*ia<<" ";
    }
}

/**
 * Function - partition
 * Partitions a vector into 3 parts taking first element as pivot
 * First part contains elements smaller than pivot
 * Second part contains pivot element itself
 * Third part contains elements larger than pivot
 * Inputs - references to three vectors, one original vector and two more for
 *          left and right parts
 * Note - Works for non repeating integer vectors
 */
void partition(const vector<int> &arr, vector<int> &la, vector<int> &ga) {
    if(arr.size() <= 1) return;
    vector<int>::const_iterator ia = arr.begin();
    int pivot = *ia;
    for(ia = arr.begin() + 1; ia < arr.end(); ia++) {
        if(*ia < pivot) {
            la.push_back(*ia);
        } else if(*ia > pivot) {
            ga.push_back(*ia);
        }
    }
}

/**
 * Function - merge
 * Merges left and right vectors into single vector, as per quicksort algorithm
 * Inputs - references to left and right vectors and target vector
 */
void merge(vector<int> &a, const vector<int> &la, const vector<int> &ga) {
    vector<int>::iterator ia = a.begin();
    int pivot = *ia;
    
    a.clear();
    
    for(vector<int>::const_iterator ila = la.begin(); ila < la.end(); ila++) {
        a.push_back(*ila);
    }
    a.push_back(pivot);
    for(vector<int>::const_iterator iga = ga.begin(); iga < ga.end(); iga++) {
        a.push_back(*iga);
    }
}

/**
 * Function - quickSortR
 * Recursive function to partition a vector and sort its parts, and then merge them
 * Inputs - Reference to a vector
 */
void quickSortR(vector <int> &ar) {
    if(ar.size() <= 1) return;
    
    cout<<endl<<"Sorting vector : ";
    printVector(ar);
    
    vector<int> la, ga;
    partition(ar, la, ga);
    
    cout<<endl;
    cout<<"Partitions : ";
    cout<<"[";
    printVector(la);
    cout<<"] < "<<ar[0]<<" < [";
    printVector(ga);
    cout<<"]";
    
    quickSortR(la);
    quickSortR(ga);
    merge(ar, la, ga);
    cout<<endl<<"Merged vector : ";
    printVector(ar);
}

int main(void) {
    vector <int>  arr;
    int arr_size;
    cout<<"Enter size of list to sort: ";
    cin >> arr_size;
    cout<<"Enter elements: "<<endl;
    for(int arr_i=0; arr_i<arr_size; arr_i++) {
        int arr_tmp;
        cout<<"#"<<arr_i+1<<": ";
        cin >> arr_tmp;
        arr.push_back(arr_tmp); 
    }
    quickSortR(arr);
    cout<<endl<<"Final merged vector : ";
    printVector(arr);
    cout<<endl;
    return 0;
}
