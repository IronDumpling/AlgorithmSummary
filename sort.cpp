//
// Created by 张楚岳 on 2021-09-11.
//
#include <iostream>
#include <vector>
/*
 * Sort Class
 * */
class Sort{
public:
    std::vector<int> sort(std::vector<int> a);

private:
    bool less(int v, int w);
    void exchange(std::vector<int> a, int i, int j);
    void show(std::vector<int> a);
    bool isSorted(std::vector<int> a);
};

/*
 * Private Method: less
 * Is used to compare two elements
 * */
bool less(int v, int w){
    if(v <= w) return true;
    else return false;
}

/*
 * Private Method: exchange
 * Is used to exchange the place of two elements
 * */
void exchange(std::vector<int> a, int i, int j){
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

/*
 * Private Method: show
 * Is used to print the vector in the same line
 * */
void show(std::vector<int> a){
    for(auto i : a){
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

/*
 * Private Method: isSorted
 * check if the vector is sorted
 * */
bool isSorted(std::vector<int> a){
    int length = a.size();
    for(int i = 1; i < length; i++){
        if(less(a[i], a[i-1])) return false;
    }
    return true;
}

/*
 * Public Method: sort
 * */
// Function 1 Selection Sort
// O(n^2)
// Theory: Select min element in the vector, then switch it with the first unsorted element
// Characteristics: Running Time has no deal with input
std::vector<int> selectionSort(std::vector<int> a){
    int length = a.size();
    // Outer for loop: Exchange min element and last unsorted element
    for(int i = 0; i < length; i++){
        int min = i;
        // Inner for loop: Find min element by comparison
        for(int j = i + 1; j < length; j++){
            if(less(a[j], a[min])) min = j;
        }
        exchange(a, i, min);
    }
    return a;
}

// Function 2 Insertion Sort
// O(n^2)
// Theory: Insert elements into appropriate place and move all elements behind
// Characteristics: Running Time depends on input
// Is Used to Deal with NON-RANDOM ARRAYS
std::vector<int> insertionSort(std::vector<int> a){
    int length = a.size();
    // Outer for loop: insert element a[i] to the left side array
    for(int i = 1; i < length; i++){
        // Inner for loop: exchange a[i] with all larger elements between a[0] and a[i - 1]
        // So a[i] is correctly inserted into left side
        // So the left side of a[i] is always sorted during the outer for loop
        for(int j = i; j > 0 && less(a[j], a[j - 1]); j--){
            // this a[j] is actually always holds the value of a[i]
            exchange(a, j, j - 1);
        }
    }
    return a;
}

// Function 2.5 Binary Insertion Sort
// O(n*m)
// Theory: Don't exchange elements, but move large elements to the right together
int binarySearch(std::vector<int> a, int lowerBound, int upperBound, int target){
    int currentIndex;
    // [lowerBound, upperBound)
    while(lowerBound < upperBound){
        currentIndex = lowerBound + (upperBound - lowerBound) / 2;
        if(a[currentIndex] > target) upperBound = currentIndex;
        else lowerBound = currentIndex + 1;
    }

    return lowerBound;
}

std::vector<int> binaryInsertionSort(std::vector<int> a){
    int length = a.size();
    // Outer for loop: insert element a[i] to the left side array
    for(int i = 1; i < length; i++){
        // Store element waiting for insertion
        int temp = a[i];

        // Do inner for loop if it is smaller than currently the biggest sorted element
        if(a[i-1] > temp){
            // Find the correct insertion place in [0, i)
            int insertIndex = binarySearch(a, 0, i-1, temp);
            // Inner for loop: move all elements in [insertIndex, i) to the right
            for(int j = i; j > insertIndex; j--){
                a[j] = a[j-1];
            }
            // Move a[i] to a[insertIndex]
            a[insertIndex] = temp;
        }
    }
    return a;
}

// Little Summary:
// Selection Sort won't access left side of current index, while Insertion Sort won't access right side of current index

// Function 3 Shell Sort
// O(n^3/2)
// Theory: Make any elements in the vector with h spacing sorted based on insertion sort
// Characteristics: Is faster for almost unsorted arrays and large arrays since it can move elements far away
std::vector<int> shellSort(std::vector<int> a){
    int length = a.size();
    int h = 1;
    // Give h the maximum value
    // So it can switch two faraway elements first
    // h = 1, 4, 13, 40, 121...
    while(h < length/3) h = 3*h + 1;
    // Outer For Loop: Traverse h (the spacing) from maximum
    while(h >= 1){
        // For Loop: Make this Sub-vector sorted by using insertion sort
        for(int i = h; i < length; i++){
            // Inner for loop: it's exactly the insertion sort except that we decrease h instead of 1
            for(int j = i; j >= h && less(a[j], a[j-h]); j -= h){
                exchange(a, j, j-h);
            }
        }
        // Decrease h from maximum value ... to 13, 4, 1
        h = h/3;
    }
    return a;
}

// Function 4 Merge Sort

// Function 5 Quick Sort

// Function 6 Stack Sort

/*
 * Main Function: Tester
 * */
void tester(){
    std::vector<int> test{19, 6, 2, 100, 17, 28, 12, 4, -9, -37, 119, 12, 18, 24};
    std::cout << "The original vector is: ";
    show(test);

    test = sort(test);
    std::cout << "The sorted vector is: ";
    show(test);
}