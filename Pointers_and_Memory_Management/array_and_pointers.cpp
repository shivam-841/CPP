1. Pointers to Arrays : A pointer to an array is a pointer that points to the entire array, rather than an individual element of the array. 
        int arr[5] = {1, 2, 3, 4, 5};
        int (*ptr)[5] = &arr; // pointer to an entire array of 5 integers
        
    
2. Arrays of Pointers : An array of pointers is an array where each element is a pointer.
        int a = 10, b = 20, c = 30;
        int* arr[3] = {&a, &b, &c};


Function Pointer : A function pointer in C++ is a pointer that can hold the address of a function. 
        Syntax: return_type (*pointer_name)(parameter_types);
        Example: int (*ptr)(int, int);

        -> Assigning a function to a Pointer:
            int add(int a, int b) {
                return a + b;
            }
            int main() {
                int (*ptr)(int, int);
                ptr = add;
            }
        
        -> Callback Functions : A callback is a function that is passed as an argument to another function and is executed inside that function.
            int double_num(int x) {
                return x * 2;
            }
            int square_num(int x) {
                return x * x;
            }
            void process_number(int (*callback)(int), int value) {
                cout << "Processed value: " << callback(value) << endl;
            }
        
        -> Function Pointer Arrays : 
            int add(int a, int b) {
                return a + b;
            }
            int subtract(int a, int b) {
                return a - b;
            }
            int multiply(int a, int b) {
                return a * b;
            }
            int main() {
                int (*operations[3])(int, int) = {add, subtract, multiply}; //an array of function pointers
            }

        -> Function Pointers with Member Functions 
            class Calculator {
            public:
                int add(int a, int b) {
                    return a + b;
                }
                int subtract(int a, int b) {
                    return a - b;
                }
            };
            int main() {
                int (Calculator::*ptr)(int, int);
                ptr = &Calculator::add;
                cout << "Add: " << (calc.*ptr)(5, 3) << endl;
            }

        Note : Always check if a function pointer is nullptr before calling it to avoid segmentation faults.
                if (callback != nullptr) {
                    callback();
                }
