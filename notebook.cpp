#include <fstream>
#include <iostream>
#include <stdexcept>

#include "notebook.hpp"

// global function definitions

Note *createNote() {
  std::string title, body;

  std::cout << "\nPlease enter the note's title: ";
  std::getline(std::cin, title);
  std::cout << "Please enter the note: ";
  std::getline(std::cin, body);

  Note *note = new Note(title, body);

  std::cout << "\nNote added!\n";

  return note;
}

EncryptedNote *createEncryptedNote() {
  std::string title, body, password;

  std::cout << "\nPlease enter the note's title: ";
  std::getline(std::cin, title);
  std::cout << "Please enter the note: ";
  std::getline(std::cin, body);
  std::cout << "Please enter the password (case sensitiive): ";
  std::getline(std::cin, password);

  EncryptedNote *Enote = new EncryptedNote(title, body, password);

  std::cout << "\nEncrypted Note added!\n";

  return Enote;
}

// class EncryptedNote definitions

void EncryptedNote::display() {
  std::string password;
  unsigned int chances = 3;

  while (chances > 0) {
    std::cout << "Please enter password to view note (case sensitive): ";
    std::cin >> password;

    if (password == password_) {
      std::cout << "\n[" << getTitle() << "]\n";
      std::cout << getBody() << "\n";
      return;
    }
    std::cout << "Incorrect password, " << --chances << " chances remaining."
              << std::endl;
  }
  throw std::out_of_range("Too many incorrect attempts. Please try again later.");
}

// class Note member function definitions

void Note::display() {
  std::cout << "\n[" << title_ << "]\n";
  std::cout << body_ << "\n";
}

// class Notebook member function definitions

void Notebook::listNotes() const {
  if (notes_.empty()) {
    throw std::range_error("No notes have been added.");
  } else {
    std::cout << "\nNotes" << std::endl;
    int index = 0;
    for (const auto &i : notes_) {
      std::cout << ++index << ". " << i->getTitle() << std::endl;
    }
  }
}

void Notebook::viewNote(const int& index) const {

  if (index > 0 && index <= notes_.size()) {
    notes_[index - 1]->display();
  } else {
    throw std::range_error("Invalid note index.");
  }
}

void Notebook::saveNotes(const std::string &notesFilename) const {
  std::ofstream outfile;
  outfile.open(notesFilename);

  for (const auto &i : notes_) {
    outfile << i->serialize();
  }

  outfile.close();

  std::cout << "\nNotes saved!\n";
}

void Notebook::loadNotes(const std::string &notesFilename) {
  notes_.clear();

  std::string temp_str;

  std::ifstream infile;
  infile.open(notesFilename);

  if (infile.fail()) {
    throw std::invalid_argument("Invalid filename. File not found.");
  }

  while (std::getline(infile, temp_str)) {
    if (temp_str == "[Note]") {
      Note *newNote = new Note;

      std::getline(infile, temp_str);
      newNote->setTitle(temp_str);
      std::getline(infile, temp_str);
      newNote->setBody(temp_str);

      notes_.push_back(newNote);
    } else if (temp_str == "[EncNote]") {
      std::string title, body, password;
      std::getline(infile, title);
      std::getline(infile, body);
      std::getline(infile, password);

      notes_.push_back(new EncryptedNote(title, body, password));
    }
  }
  infile.close();

  std::cout << "\nNotes loaded!\n";
}
