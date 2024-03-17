#include <list>
#include <iostream>
using namespace std;

void printList(const list<int>& lst) {
    for (int n : lst) cout << n << " ";
    cout << endl;
}
// Custom function to sort the list (Bubble Sort)
void customSort(list<int>& lst) {
    bool swapped;
    do {
        swapped = false;
        for (auto it = lst.begin(); it != prev(lst.end()); ++it) {
            if (*it > *next(it)) {
                swap(*it, *next(it));
                swapped = true;
            }
        }
    } while (swapped);
}
// Custom function to merge two sorted lists
list<int> mergeSortedLists(const list<int>& list1, const list<int>& list2) {
    list<int> mergedList;
    auto it1 = list1.begin();
    auto it2 = list2.begin();
    while (it1 != list1.end() && it2 != list2.end()) {
        if (*it1 < *it2) {
            mergedList.push_back(*it1);
            ++it1;
        }
        else {
            mergedList.push_back(*it2);
            ++it2;
        }
    }
    // Add remaining elements from list1
    while (it1 != list1.end()) {
        mergedList.push_back(*it1);
        ++it1;
    }
    // Add remaining elements from list2
    while (it2 != list2.end()) {
        mergedList.push_back(*it2);
        ++it2;
    }
    return mergedList;
}

int main() {
    list<int> myList = { 1, 2, 3, 4, 5 };
    myList.push_back(6);  // Add to the end
    myList.push_front(0); // Add to the front
    printList(myList);

 // Sorting the list
    customSort(myList);
    cout << "Sorted List: ";
    printList(myList);
// Creating another sorted list
    list<int> otherList = { 7, 8, 9 };
    otherList.push_front(-1);
    cout << "Other List: ";
    printList(otherList);

  // Merging the two sorted lists
    list<int> mergedList = mergeSortedLists(myList, otherList);
    cout << "Merged Sorted List: ";
    printList(mergedList);

    return 0;
}
