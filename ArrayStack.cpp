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
            n = 0;
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

        void add(int i, T x) {
            if (n + 1 >= a.length) resize();
            for (int j = n; j > i; j--)
                a[j] = a[j - 1];
            a[i] = x;
            n++;
        }

        T remove(int i) {
            T x = a[i];
            for (int j = i; j < n - 1; j++)
                a[j] = a[j + 1];
            n--;
            if (a.length >= 3 * n) resize();
            return x;
        }

        void resize() {
            backing_array<T> b(max(2 * n, 1));
            for (int i = 0; i < n; i++)
                b[i] = a[i];
            a = b;
        }

        void show() {
            for (int i = 0; i < length; i++)
                cout << a[i] << ",";
            cout << endl;
        }

    private:
        backing_array<int> a;
};


int main() {
    ArrayStack<int> as(10);

    for (int i = 0; i < 10; i++) {
        as.add(i, i);
    }

    as.show();
    as.add(3, 10);
    as.show();
    as.remove(3);
    as.show();
}