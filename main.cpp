#include <iostream>
#include <string>
#include <vector>

#include "notebook.hpp"

int main() {
  char choice;
  size_t index;
  std::string filename, newTitle, newBody;
  Notebook Diary;
  Note newNote;

  std::cout << "Welcome to TuffyNotes!" << std::endl;

  // do while loop is used so that the menu is displayed at least once even when
  // choice has not yet been defined
  do {
    std::cout << "[C] Create a note" << std::endl;
    std::cout << "[L] List notes" << std::endl;
    std::cout << "[V] View note" << std::endl;
    std::cout << "[S] Save notes" << std::endl;
    std::cout << "[O] Load notes" << std::endl;
    std::cout << "[E] Exit" << std::endl;
    std::cout << "Choice: ";
    std::cin >> choice;
    std::cin.ignore();

    // begin switch statement to create menu choice scenarios
    switch (choice) {
    case 'c':
    case 'C':
      std::cout << "\nPlease enter the note's title: ";
      std::getline(std::cin, newTitle);
      newNote.title_ = newTitle;

      std::cout << "Please enter the note: ";
      std::getline(std::cin, newBody);
      newNote.body_ = newBody;

      Diary.addNote(newNote);
      break;

    case 'l':
    case 'L':
      Diary.listNotes();
      break;

    case 'v':
    case 'V':
      Diary.listNotes();
      std::cout << "Please input note index: ";
      std::cin >> index;
      std::cin.ignore();
      if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore();
        std::cout << "\nInvalid note index.\n" << std::endl;
      } else {
        Diary.viewNote(index);
      }
      break;

    case 's':
    case 'S':
      std::cout << "\nPlease enter the filename: ";
      std::cin >> filename;

      Diary.saveNotes(filename);
      break;

    case 'o':
    case 'O':
      std::cout << "\nPlease enter the filename: ";
      std::cin >> filename;
      Diary.loadNotes(filename);
      break;

    case 'e':
    case 'E':
      std::cout << std::endl << "Thank you for using Notebook!" << std::endl;
      break;
    default:
      std::cout << std::endl
                << "Invalid choice. Please try again." << std::endl
                << std::endl;
    }
    // continue this statement until user inputs 'E' or 'e'
  } while (choice != 'E' && choice != 'e');

  return 0;
}
