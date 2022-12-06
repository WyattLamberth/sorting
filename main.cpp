#include <iostream>
#include <vector> 
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

// prints the vector given as input in one line.
void print_vector(vector<int> v){
    for (int i = 0; i < v.size(); i++){
        cout << v.at(i) << " ";
    }
    cout << endl;
}

// The bubble sort function
// sorts the vector using the bubble sort algorithm
// time complexity: O(n^2)
void bubblesort(vector<int> &v){

    cout << "***************************************" << endl;
    cout << "Unsorted: ";
    print_vector(v);

    int temp, swaps = 0;
    for (int i = 0; i < v.size(); i++){
        for (int k = i+1; k < v.size(); k++){
            if (v.at(i) > v.at(k)){
                temp = v.at(i);
                v.at(i) = v.at(k);
                v.at(k) = temp;
                swaps++;
            }
        }
        print_vector(v);
    }

    cout << "Swaps: " << swaps << endl;

    cout << "Sorted: ";
    print_vector(v);
    cout << "***************************************" << endl;
}

// the insertion sort function
// sorts the vector using the insertion sort algorithm
// time complexity: O(n^2)
void insertionsort(vector<int> &v){
    cout << "***************************************" << endl;
    cout << "Unsorted: ";
    print_vector(v);

    int temp, s, k, swaps = 0;
    s = v.size();

    for (int i = 0; i < s; i++){
        temp = v.at(i);

        k = i - 1;

        while (k >= 0 && temp <= v.at(k)){
            v.at(k + 1) = v.at(k);
            k--;
            swaps++;
        }
        v.at(k + 1) = temp;

        print_vector(v);
    }
    
    cout << "Swaps: " << swaps << endl;
    cout << "Sorted: ";
    print_vector(v);
    cout << "***************************************" << endl;
}

// the selection sort function
// sorts the vector using the selection sort algorithm
// time complexity: O(n^2)
void selectionsort(vector<int> &v){
    cout << "***************************************" << endl;
    cout << "Unsorted: ";
    print_vector(v);

    int temp, s, min, swaps = 0;

    s = v.size();

    for (int i = 0; i < s; i++){
        min = i;

        for (int k = i + 1; k < s; k++){
            if (v.at(k) < v.at(min))
                min = k;
        }

        temp = v.at(min);
        v.at(min) = v.at(i);
        v.at(i) = temp;
        swaps++;

        print_vector(v);
    }

    cout << "Swaps: " << swaps << endl;
    cout << "Sorted: ";
    print_vector(v);
    cout << "***************************************" << endl;

}

// helper function for the merge sort function
// compares and merges unsorted subarrays into one sorted array
void merge(vector<int>& v, int s, int m, int e) {
	
    // temp is used to temporary store the vector obtained by merging
    // elements from [s to m] and [m+1 to e] in v
	vector<int> temp;

	int i, j;
	i = s;
	j = m + 1;

	while (i <= m && j <= e) {

		if (v[i] <= v[j]) {
			temp.push_back(v[i]);
			++i;
		}
		else {
			temp.push_back(v[j]);
			++j;
		}

	}

	while (i <= m) {
		temp.push_back(v[i]);
		++i;
	}

	while (j <= e) {
		temp.push_back(v[j]);
		++j;
	}

	for (int i = s; i <= e; ++i)
		v[i] = temp[i - s];

}

// the merge sort function
// sorts the vector in the range [s to e] in v using
// merge sort algorithm
// time complexity: O(n * log(n))
void mergesort(vector<int>& v, int s, int e) {
	if (s < e) {
		int m = (s + e) / 2;
		mergesort(v, s, m);
		mergesort(v, m + 1, e);
		merge(v, s, m, e);
	}

    print_vector(v);
}

int main(){

    ifstream fin("nums.txt");
    vector<int> numbers;

    int temp;
    while(fin >> temp){
        numbers.push_back(temp);
    }

    vector<int> unsorted = numbers;

    int choice = -1;
    while (choice != 0){

        numbers = unsorted;

        cout << "Which sort do you want to use?" << endl;
        cout << "0. Exit" << endl;
        cout << "1. Bubble Sort" << endl;
        cout << "2. Insertion Sort" << endl;
        cout << "3. Selection Sort" << endl;
        cout << "4. Merge Sort" << endl;
        cin >> choice;

        switch (choice) {
            case 0: 
                cout << "Goodbye." << endl;
                break;
            case 1: 
                bubblesort(numbers);
                break;
            case 2:
                insertionsort(numbers);
                break;
            case 3:
                selectionsort(numbers);
                break;
            case 4:
                int s = numbers.size() - 1;
                cout << "***************************************" << endl;
                cout << "Unsorted: ";
                print_vector(numbers);
                mergesort(numbers, 0, s);
                cout << "Sorted: ";
                print_vector(numbers);
                cout << "***************************************" << endl;
                break;
        }
    }

}