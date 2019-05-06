#include <iostream>
#include <string>

#include "notebook.hpp"

int main() {
  char choice;
  std::string rem;
  std::string notes_filename;
  int index;

  bool display_menu = true;

  Notebook note_list;

  std::cout << "Welcome to the eNotes!\n";

  do {
    std::cout << std::endl;
    std::cout << "[C] Create a note" << std::endl;
    std::cout << "[N] Create an encrypted note" << std::endl;
    std::cout << "[L] List notes" << std::endl;
    std::cout << "[V] View note" << std::endl;
    std::cout << "[S] Save notes" << std::endl;
    std::cout << "[O] Load notes" << std::endl;
    std::cout << "[E] Exit" << std::endl;
    std::cout << "Choice: ";
    std::cin >> choice;

    // ignore the newline char that follows the user input for choice, but
    // also check for multiple character input - therefore, read in the rest
    // of the line. this will handle the case where the user enters more than
    // one character, and if that has occurred, treat it as invalid since we
    // cannot assume the first char entered is the choice the user desires
    std::getline(std::cin, rem);
    if (rem.length() > 0) {
      choice = ' '; // set to invalid "choice"
    }

    switch (choice) {
    case 'C':
    case 'c':
      note_list.addNote(createNote());
      break;
    case 'N':
    case 'n':
      note_list.addNote(createEncryptedNote());
      break;
    case 'L':
    case 'l':
      note_list.listNotes();
      break;
    case 'V':
    case 'v':
      note_list.listNotes();
      std::cout << "\nPlease input note index: ";
      std::cin >> index;
      note_list.viewNote(index);
      break;
    case 'S':
    case 's':
      std::cout << "\nPlease enter the filename: ";
      std::getline(std::cin, notes_filename);

      note_list.saveNotes(notes_filename);
      break;
    case 'O':
    case 'o':
      std::cout << "\nPlease enter the filename: ";
      std::getline(std::cin, notes_filename);

      note_list.loadNotes(notes_filename);
      break;
    case 'E':
    case 'e':
      display_menu = false;
      break;
    default:
      std::cout << "\nInvalid choice. Please try again.\n";
      break;
    }
  } while (display_menu);

  std::cout << "\nThank you for using eNotes!\n";

  return 0;
}
