// function implementation file

#include "notebook.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

// Adds input Note to back of the Notebook
void Notebook::addNote(const Note &newNote) {
  list_.push_back(newNote);
  std::cout << "\nNote added!\n" << std::endl;
}

void Notebook::listNotes() const {
  if (list_.empty()) {
    std::cout << "\nNo notes have been added.\n" << std::endl;
    return;
  }
  std::cout << "\nNotes" << std::endl;
  // loop through list_
  // prints with format: #. title
  for (int i = 0; i < list_.size(); i++) {
    std::cout << i + 1 << ". " << list_[i].title_ << std::endl;
  }
  std::cout << std::endl;
}

void Notebook::viewNote(const size_t &index) {
  if (list_.empty()) {
    std::cout << "\nNo notes have been added.\n" << std::endl;
    return;
  }

  if (index <= 0 || index > list_.size()) {
    std::cout << "\nInvalid note index.\n" << std::endl;
    return;
  }
  std::cout << "\n[" << list_[index - 1].title_ << "]" << std::endl;
  std::cout << list_[index - 1].body_ << std::endl;
  std::cout << std::endl;
  return;
}

void Notebook::saveNotes(const std::string &filename) {
  std::ofstream input_file;
  input_file.open(filename);

  for (const auto &i : list_) {
    input_file << "[Note]\n";
    input_file << i.title_ << "\n";
    input_file << i.body_ << "\n";
  }

  std::cout << "\nNotes saved!\n" << std::endl;
}

void Notebook::loadNotes(const std::string &filename) {
  std::ifstream input_file;
  input_file.open(filename);

  if (!input_file.is_open()) {
    std::cout << "Error: No file named " << filename << std::endl;
    return;
  }
  list_.clear();
  std::string newLine, newTitle, newBody;

  // skip over first [Note] incedence
  input_file >> newBody;
  input_file.ignore();

  while (!input_file.eof()) {
    std::getline(input_file, newTitle);
    newBody = ""; // clear newBody
    while (std::getline(input_file, newLine)) {
      if (newLine != "[Note]") {
        newBody += newLine; // add each line to newBody until [Note] is found
      } else {
        break;
      }
    }
    Note newNote(newTitle, newBody);
    list_.push_back(newNote);
  }

  std::cout << "\nNotes loaded!\n" << std::endl;
}
