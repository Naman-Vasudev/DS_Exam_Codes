#include <iostream>
#include <queue>
using namespace std;

class heap {
public:
    int arr[100];
    int size = 0;

    heap() {
        arr[0] = -1;
        size = 0;
    }

    // INSERT (Max Heap)
    // TC: O(log n), SC: O(1)
    void insert_value(int value)
    {
        size++;
        int index = size;
        arr[index] = value;

        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else return;
        }
    }

    // PRINT HEAP
    void print()
    {
        for (int i = 1; i <= size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    // DELETE ROOT (Max Heap)
    // TC: O(log n), SC: O(1)
    void deleteion()
    {
        if (size == 0)
        {
            cout << "EMPTY HEAP\n";
            return;
        }
        arr[1] = arr[size];
        size--;

        int i = 1;
        while (i <= size)
        {
            int left = 2 * i;
            int right = 2 * i + 1;

            if (left <= size && arr[i] < arr[left])
            {
                swap(arr[i], arr[left]);
                i = left;
            }
            else if (right <= size && arr[i] < arr[right])
            {
                swap(arr[i], arr[right]);
                i = right;
            }
            else break;
        }
    }

    // RETURN MAX (highest priority)
    int get_max()
    {
        if (size == 0) return -1;
        return arr[1];
    }

    // BUILD HEAP FROM PRIORITY QUEUE (max)
    void build_from_max_pq(priority_queue<int> pq)
    {
        size = pq.size();
        int i = 1;
        while (!pq.empty())
        {
            arr[i++] = pq.top();
            pq.pop();
        }
    }

    // BUILD HEAP FROM MIN PRIORITY QUEUE
    void build_from_min_pq(priority_queue<int, vector<int>, greater<int>> pq)
    {
        size = pq.size();
        int i = 1;
        while (!pq.empty())
        {
            arr[i++] = pq.top();
            pq.pop();
        }
    }
};

// HEAPIFY – Max
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && arr[largest] < arr[left])
        largest = left;
    if (right <= n && arr[largest] < arr[right])
        largest = right;

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

// HEAP SORT – Max
void heap_sort(int arr[], int n)
{
    int size = n;
    while (size > 1)
    {
        swap(arr[size], arr[1]);
        size--;
        heapify(arr, size, 1);
    }
}

int main()
{
    cout << "=== Max Heap Demo ===\n";
    heap h;

    h.insert_value(50);
    h.insert_value(30);
    h.insert_value(20);
    h.insert_value(40);
    h.insert_value(70);
    h.insert_value(60);

    cout << "Heap after insertions: ";
    h.print();

    cout << "Current highest priority = " << h.get_max() << endl;

    cout << "\nInserting 90 (new highest priority)\n";
    h.insert_value(90);

    cout << "New highest priority = " << h.get_max() << endl;

    cout << "\nDeleting highest priority...\n";
    h.deleteion();

    cout << "Heap now: ";
    h.print();

    // ---------------------------------------------------
    // PRIORITY QUEUE <-> HEAP (ALL 4 CASES)
    // ---------------------------------------------------
    cout << "\n=== Priority Queue Conversions ===\n";

    // 1) HEAP -> MAX PRIORITY QUEUE
    priority_queue<int> maxpq;
    for (int i = 1; i <= h.size; i++) maxpq.push(h.arr[i]);

    cout << "Converted HEAP → Max PQ top = " << maxpq.top() << endl;

    // 2) HEAP -> MIN PRIORITY QUEUE
    priority_queue<int, vector<int>, greater<int>> minpq;
    for (int i = 1; i <= h.size; i++) minpq.push(h.arr[i]);

    cout << "Converted HEAP → Min PQ top = " << minpq.top() << endl;

    // 3) MAX PRIORITY QUEUE → HEAP
    heap h2;
    h2.build_from_max_pq(maxpq);

    cout << "Converted Max PQ → HEAP: ";
    h2.print();

    // 4) MIN PRIORITY QUEUE → HEAP
    heap h3;
    h3.build_from_min_pq(minpq);

    cout << "Converted Min PQ → HEAP: ";
    h3.print();

    return 0;
}
