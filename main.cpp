#include <iostream>
#include <vector> 
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

void print_vector(vector<int> v){
    for (int i = 0; i < v.size(); i++){
        cout << v.at(i) << " ";
    }
    cout << endl;
}

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
        }
    }

}