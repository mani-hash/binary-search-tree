# Binary Search Tree

## Table of Contents
1. [Student Information](#student-information)
2. [Testing Environment](#testing-environment)
3. [Prerequisites](#prerequisites)
4. [How to execute the program](#how-to-execute-the-program)
5. [Remove build files](#remove-build-files)
6. [Special Notes](#special-notes)

## Student Information
- **Name:** Manimehalan Thiyagarajan
- **Index Number:** 23001062
- **Email Address:** 2023cs106@stu.ucsc.cmb.ac.lk

## Testing Environment
- **Tested on Linux:** Yes
  - This code was tested on pop os 22.04

## Prerequisites
- **Compiler:** GCC
- **Build System:** Make
- **Input text file:** input.txt in `data/` directory

## How to execute the program
1. **Build the project:**
   ```sh
   make
   ```
2. **Run the program:**
    ```sh
    make run
    ```

## Remove build files
1. **Clean the build files: (Optional)**
    ```sh
    make clean
    ```
## Special Notes
- `data/input.txt` is necessary for the project to function.
- Modify the contents of `input.txt` to change binary search tree data
- Data in `input.txt` can be in **either** of the below formats
   - All the data can be entered in one line separated by **commas** and must end with a fullstop **"."**
   ```
   Cat, Dog, Rat, Bat, Bag, Nut, Mug, Cup, Kid, Dig.
   ```
   - Else each word can be entered in the file line by line as shown below
   ```
   Cat
   Dog
   Rat
   Bat
   Bag
   Nut
   Mug
   Cup
   Kid
   Dig
   ```
- The final executable file is stored in `build/` directory and named as `bst`