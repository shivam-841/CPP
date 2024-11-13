
Smart pointers are wrapper classes around raw pointers, designed to manage the lifetime of dynamically allocated objects. 
 -> It automatically handle the memory deallocation as it goes out of scope.
 -> It has been defined in the <memory> header.
 -> There are three most commonly used:
        1. std::unique_ptr
        2. std::shared_ptr
        3. std::weak_ptr



        -------  std::unique_ptr  ----------
A std::unique_ptr represents exclusive ownership of a dynamically allocated object. 
 -> Only one unique_ptr can own a particular object at any given time. 
 -> automatic deallocation as it goes out of the scope
 -> move semantic exists, no copy exists.


// creats a new unique ptr
    unique_ptr<int>ptr1 = make_unique<int>(20);
    cout<<*ptr1<<endl;

// passing a variable as referemce is not possible easily or copying it
    int a = 10; 
    unique_ptr<int>ptr1 = make_unique<int>(a);
    unique_ptr<int>ptr2 = ptr1; //not possible will throw a error
    cout<<*ptr1<<" "<<*ptr2<<endl;

// move symantics
    int a = 10;
    unique_ptr<int>ptr1 = make_unique<int>(a);
    unique_ptr<int>ptr2 = move(ptr1);
    cout<<*ptr1<<endl;


       ----------------- std::shared_ptr --------------------
A std::shared_ptr represents shared ownership of a dynamically allocated object.
 -> Multiple shared_ptr instances can point to the same object
 -> Object is only get deallocated once all shared_ptr pointing to it is destroyed or reset.
 -> Reference Counting: Each shared_ptr maintains a reference count. When a new shared_ptr is created from another shared_ptr, the reference count is incremented.

// example of shared_ptr showing shared ownership, using method "use_count()" to count the reference count and using method "reset" to remove the ownership from the pointer.
    int a = 10;
    shared_ptr<int>ptr1 = make_shared<int>(a);
    shared_ptr<int>ptr2 = ptr1; //shared the ownership
    cout<<ptr1.use_count()<<" "<<ptr2.use_count()<<endl; //prints 2 2
    ptr2.reset(); //reset the pointer
    cout<<ptr1.use_count()<<" "<<ptr2.use_count()<<endl; //prints 1 0



        --------------- std::weak_ptr --------------------
A std::weak_ptr is a non-owning reference to a resource managed by a shared_ptr.
 -> Non-Owning reference to a resource managed by a shared_ptr
 -> Can create a shared_ptr from a weak_ptr using lock()
 -> It is often used to break cycles of shared_ptr references, where two objects references each other and never get deleted.


    std::shared_ptr<int> ptr1 = std::make_shared<int>(10);
    // Create a weak pointer from the shared pointer
    std::weak_ptr<int> weakPtr = ptr1;
    // Convert weak_ptr to shared_ptr
    std::shared_ptr<int> ptr2 = weakPtr.lock();


//------------------------------------------- SUMARRY -----------------------
Use std::unique_ptr when you want sole ownership of a resource, and no other entity should share ownership.
Use std::shared_ptr when you need shared ownership, and multiple entities can own the same resource.
Use std::weak_ptr to prevent circular references and break ownership cycles in cases where objects refer to each other.