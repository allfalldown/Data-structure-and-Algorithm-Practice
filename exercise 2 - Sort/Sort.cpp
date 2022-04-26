#include <iostream>
#include <random>
#include <time.h>
#include <algorithm>

using namespace std;

void InterchangeSort(int a[], int n);
void bubbleSort(int a[], int n);
void selectionSort(int a[], int n);
void heapSort(int a[], int n);
void heapify(int a[], int n, int vt);
void buildheap(int a[], int n);
void mergeSort(int a[], int left, int right);
void Merge(int a[], int left, int mid, int right);
void quickSort(int a[], int d, int c);
void insertionSort(int arr[], int n);
void generateIntArray(int a[], int& n);
void output(int a[], int n);
int random(int min, int max);

int main(){   

    clock_t start, end;
    int a[10000];
    int n = 10000;

    generateIntArray(a, n);    
    cout << "Thuat toan sort: " << endl;
    cout << "1. Interchange Sort. " << endl;
    cout << "2. Bubble Sort " << endl;
    cout << "3. Selection Sort " << endl;
    cout << "4. Heap Sort " << endl;
    cout << "5. Merge Sort " << endl;
    cout << "6. Quick Sort " << endl;  
    cout << "7. Intersection Sort " << endl;
    int sw; cout << "Chon thuat toan can sap xep: "; cin >> sw;
    if (sw == 1){
        cout << "Interchange Sort: " << endl;
        start = clock();
        InterchangeSort(a, n);
        output(a, n);
        end = clock();
        cout << endl << "Thoi gian chay thuat toan: ";
        cout << (double)(end - start) / CLOCKS_PER_SEC;
    }else if (sw == 2){
        cout << "Bubble Sort: " << endl;
        start = clock();
        bubbleSort(a, n);
        output(a, n);
        end = clock();
        cout << endl << "Thoi gian chay thuat toan: ";
        cout << (double)(end - start) / CLOCKS_PER_SEC;
    }else if (sw == 3){
        cout << "Selection Sort: " << endl;
        start = clock();
        selectionSort(a, n);
        output(a, n);
        end = clock();
        cout << endl << "Thoi gian chay thuat toan: ";
        cout << (double)(end - start) / CLOCKS_PER_SEC;
    }else if (sw == 4){
        cout << "Heap Sort: " << endl;
        start = clock();
        heapSort(a, n);
        output(a, n);
        end = clock();
        cout << endl << "Thoi gian chay thuat toan: ";
        cout << (double)(end - start) / CLOCKS_PER_SEC;
    }else if (sw == 5){
        cout << "Merge Sort: " << endl;
        start = clock();
        mergeSort(a, 0, n-1);
        output(a, n);
        end = clock();
        cout << endl << "Thoi gian chay thuat toan: ";
        cout << (double)(end - start) / CLOCKS_PER_SEC;
    }else if (sw == 6){
        cout << "Quirck Sort: " << endl;
        start = clock();
        quickSort(a, 0, n - 1);
        output(a, n);
        end = clock();
        cout << endl << "Thoi gian chay thuat toan: ";
        cout << (double)(end - start) / CLOCKS_PER_SEC;
    } else if (sw == 7){
        cout << "Intersection Sort: " << endl;
        start = clock();
        insertionSort(a, n);
        output(a, n);
        end = clock();
        cout << endl << "Thoi gian chay thuat toan: ";
        cout << (double)(end - start) / CLOCKS_PER_SEC;
    }
    cout << endl;
    return 0;
}

int random(int min, int max){
    static bool first = true;
    if (first){
        srand(time(NULL));
        first = false;
    }
    return min + rand() % ((max + 1) - min);
}

void InterchangeSort(int a[], int n){
    for (int i = 0; i < n - 2; i++)
        for (int j = i + 1; j < n - 1; j++){
            if (a[i] > a[j]){
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
}

void bubbleSort(int a[], int n){
    for (int i = 0; i < n - 2; i++)
        for (int j = n - 1; j >= i + 1; j--){
            if (a[j] < a[j - 1]){
                int temp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = temp;
            }
        }
}

void selectionSort(int a[], int n){
    for (int i = 0; i < n - 2; i++){
        int lc = i;
        for (int j = i + 1; j < n - 1; j++){
            if (a[j] < a[lc])
                lc = j;
        }
        int temp = a[i];
        a[i] = a[lc];
        a[lc] = temp;
    }
}

void heapify(int a[], int n, int vt){
    while (vt <= (n / 2) - 1){
        int child1 = 2 * vt + 1;
        int child2 = 2 * vt + 2;
        int lc = child1;
        if (child2 < n && a[lc] < a[child2])
            lc = child2;
        if (a[vt] < a[lc])
            swap(a[vt], a[lc]);
        vt = lc;
    }
}

void buildheap(int a[], int n){
    for (int i = n / 2; i >= 0; i--)
        heapify(a, n, i);
}

void heapSort(int a[], int n){
    buildheap(a, n);
    int length = n;
    while (length > 1){
        swap(a[0], a[length - 1]);
        length--;
        heapify(a, length, 0);
    }
}

void Merge(int a[], int Left, int Mid, int Right){
    int* temp = new int[Right - Left + 1];
    int n;
    int i = Left;
    int j = Mid + 1;
    n = 0;
    while (!(i > Mid && j > Right)){
        if ((i <= Mid && j <= Right && a[i] < a[j]) || (j > Right))
            temp[n++] = a[i++];
        else
            temp[n++] = a[j++];
    }
    for (i = 0; i < n; i++)
        a[Left + i] = temp[i];
    delete[] temp;
}

void mergeSort(int a[], int left, int right){
    if (left < right){
        int mid = (left + right) / 2;
        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);
        Merge(a, left, mid, right);
    }
}

void quickSort(int a[], int d, int c){
    if (d > c)
        return;
    int low = d;
    int high = c;
    int sw = a[(d + c) / 2];
    do{
        while (a[low] < sw)
            low++;
        while (a[high] > sw)
            high--;
        if (low <= high){
            swap(a[low], a[high]);
            low++;
            high--;
        }
    } while (low < high);
    if (d < high)
        quickSort(a, d, high);
    if (c > low)
        quickSort(a, low, c);
}

void insertionSort(int arr[], int n){
    int i, key, j;
    for (i = 1; i < n; i++){
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void generateIntArray(int a[], int& n){
    for (int i = 0; i < n; i++)
        a[i] = random(0, 10000);
}

void output(int a[], int n){
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}
