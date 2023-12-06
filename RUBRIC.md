# C++ Capstone Project Rubric

## README (All Rubric Points REQUIRED)

### 1. README with instructions is included with the project

- The README is included with the project and has instructions for building/running the project.
- If any additional libraries are needed to run the project, these are indicated with cross-platform installation instructions.

### 2. README indicates the new features you added to the game

- The README indicates the new features you added to the game, along with the expected behavior or output of the program.

### 3. README indicates which rubric points are addressed

- The README indicates which rubric points are addressed.
- The README also indicates where in the code (i.e. files and line numbers) that the rubric points are addressed.

## Compiling and Testing (All Rubric Points REQUIRED)

### 1. The submission must compile and run without errors on the Udacity project workspace.

- We strongly recommend using **cmake** and **make**, as provided in the starter repos.
- If you choose another build system, the code must be compiled on the Udacity project workspace.

## Loops, Functions, I/O - meet at least 2 criteria

### 1. The project demonstrates an understanding of C++ functions and control structures.

- A variety of control structures are added to the project.
- The project code is clearly organized into functions.

### 2. The project reads data from a file and processes the data, or the program writes data to a file.

- The project reads data from an external file or writes data to a file as part of the necessary operation of the program.

### 3. The project accepts user input and processes the input.

- In addition to controlling the snake, the game can also receive new types of input from the player.

### 4. The project uses data structures and immutable variables.

- The project uses arrays or vectors **and** uses constant variables.

## Object-Oriented Programming - meet at least 3 criteria

### 1. One or more classes are added to the project with appropriate access specifiers for class members.

- Classes are organized with attributes to hold data and methods to perform tasks.
- All class data members are explicitly specified as public, protected, or private.
- Member data that is subject to an invariant is hidden from the user and accessed via member methods.

### 2. Class constructors utilize member initialization lists.

- All class members that are set to argument values are initialized through member initialization lists.

### 3. Classes abstract implementation details from their interfaces.

- All class member functions document their effects, either through function names, comments, or formal documentation.
- Member functions do not change the program state in undocumented ways.

### 4. Overloaded functions allow the same function to operate on different parameters.

- One function is overloaded with different signatures for the same function name.

### 5. Classes follow an appropriate inheritance hierarchy with virtual and override functions.

- Inheritance hierarchies are logical.
- One member function in an inherited class overrides a virtual base class member function.

### 6. Templates generalize functions or classes in the project.

- One function or class is declared with a template that allows it to accept a generic parameter.

## Memory Management - meet at least 3 criteria

### 1. The project makes use of references in function declarations.

- At least two variables are defined as references, or two functions use pass-by-reference in the project code.

### 2. The project uses destructors appropriately.

- At least one class that uses unmanaged dynamically allocated memory, along with any class that otherwise needs to modify state upon the termination of an object, uses a destructor.

### 3. The project uses scope / Resource Acquisition Is Initialization (RAII) where appropriate.

- The project follows the Resource Acquisition Is Initialization pattern where appropriate, by allocating objects at compile-time, initializing objects when they are declared, and utilizing scope to ensure their automatic destruction.

### 4. The project follows the Rule of 5.

- For all classes, if any one of the copy constructor, copy assignment operator, move constructor, move assignment operator, and destructor are defined, then all of these functions are defined.

### 5. The project uses move semantics to move data instead of copying it, where possible.

- The project relies on the move semantics, instead of copying the object.

### 6. The project uses smart pointers instead of raw pointers.

- The project uses at least one smart pointer: `unique_ptr`, `shared_ptr`, or `weak_ptr`.

## Concurrency - meet at least 2 criteria

### 1. The project uses multithreading.

- The project uses multiple threads or async tasks in the execution.

### 2. A promise and future is used in the project.

- A promise and future is used to pass data from a worker thread to a parent thread in the project code.

### 3. A mutex or lock is used in the project.

- A mutex or lock (e.g. `std::lock_guard` or `std::unique_lock`) is used to protect data that is shared across multiple threads in the project code.

### 4. A condition variable is used in the project.

- A `std::condition_variable` is used in the project code to synchronize thread execution.
