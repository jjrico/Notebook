#Notebook
Program name: Notebook
Included files: Notebook.hpp Notebook.cpp main.cpp
Created by: Jeremy Rico
Last modified: April 25, 2019
Language: C++
Compile command: clang++ -std=c++17 main.cpp notebook.cpp -o main
                ./main
===============================================================================
Program Summary:
  This program creates a menu-based command-line interface that allows the user
to create, edit, save, and load notes. The user can choose to create either a
regular note consisting of a title and a body, or an encrypted note which
requires a password to view. The program continues to ask for user
input until the user enters "E" in order to exit the program.
