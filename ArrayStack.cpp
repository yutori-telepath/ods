#include <iostream>

using namespace std;

template<class T>
class backing_array {
    public:
        T *a;
        int length;

        backing_array(int len) {
            length = len;
            a = new T[length];
        }

        T& operator[](int i) {
            assert(i >= 0 && i < length);
            return a[i];
        }

        backing_array<T>& operator=(backing_array<T> &b) {
            if (a != NULL) delete[] a;
            a = b.a;
            b.a = NULL;
            length = b.length;
            return *this;
        }
};


template<class T>
class ArrayStack {
    public:
        int n;
        int length;

        ArrayStack(int len):a(len) {
            length = len;
        }

        int size() {
            return n;
        }

        T get(int i) {
            return a[i];
        }

        T set(int i, T x) {
            T y = a[i];
            a[i] = x;
            return y;
        }

    private:
        backing_array<int> a;
};


int main() {
    ArrayStack<int> as(10);
    for (int i = 0; i < 10; i++) {
        as.set(i, i * 2);
        cout << as.get(i) << endl;
    }
}